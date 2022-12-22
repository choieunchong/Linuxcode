#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <limits.h>                     /* USHRT_MAX 상수를 위해서 사용한다. */
#include <unistd.h>

#include "bmpHeader.h"


inline unsigned char clip(int value, int min, int max);
unsigned char clip(int value, int min, int max)                                             // clip 함수, 값이 255이상이면 255로, 0보다 작으면 0으로 설정
{
    return(value > max ? max : value < min ? min : value);
}

/* 이미지 데이터의 경계 검사를 위한 매크로 */
#define LIMIT_UBYTE(n) ((n)>UCHAR_MAX)?UCHAR_MAX:((n)<0)?0:(n)

typedef unsigned char ubyte;


int main(int argc, char** argv)
{
    FILE* fp;
    BITMAPFILEHEADER bmpHeader;             /* BMP FILE INFO */
    BITMAPINFOHEADER bmpInfoHeader;     /* BMP IMAGE INFO */
    RGBQUAD* palrgb;
    ubyte* inimg, * outimg;
    int x, y, z, imageSize;

    if (argc != 3) {
        fprintf(stderr, "usage : %s input.bmp output.bmp\n", argv[0]);
        return -1;
    }

    /***** read bmp *****/
    if ((fp = fopen(argv[1], "rb")) == NULL) {                                                      // 원본 파일 오픈
        fprintf(stderr, "Error : Failed to open file...?n");
        return -1;
    }

    /* BITMAPFILEHEADER 구조체의 데이터 */
    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);                                             // 파일에서 파일헤더 읽어서 구조체에 저장

    /* BITMAPINFOHEADER 구조체의 데이터 */
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);                                         // 파일에서 인포헤더 읽어서 구조체에 저장



    /* 트루 컬러를 지원하면 변환할 수 없다. */
    if (bmpInfoHeader.biBitCount != 24) {                                                           // 24비트 지원안하면 실행 안함
        perror("This image file doesn't supports 24bit color\n");
        fclose(fp);
        return -1;
    }

    int elemSize = bmpInfoHeader.biBitCount / 8;                                                    // rgb 개수
    int size = bmpInfoHeader.biWidth * elemSize;                                                    // 열의 개수
    int psize = (bmpInfoHeader.biWidth + 2) * elemSize;                                             // 패딩의 열의 개수
    imageSize = size * bmpInfoHeader.biHeight;                                                      // 행열의 개수


    /* 이미지의 해상도(넓이 × 깊이) */
    printf("Resolution : %d x %d\n", bmpInfoHeader.biWidth, bmpInfoHeader.biHeight);
    printf("Bit Count : %d\n", bmpInfoHeader.biBitCount);     /* 픽셀당 비트 수(색상) */
    printf("Image Size : %d\n", imageSize);

    inimg = (ubyte*)malloc(sizeof(ubyte) * imageSize);                                              // 원본 이미지를 저장할 메모리 할당
    outimg = (ubyte*)malloc(sizeof(ubyte) * imageSize);                                             // 출력 이미지를 저장할 메모리 할당
    palrgb = (RGBQUAD*)malloc(sizeof(ubyte) * 256);

    fread(inimg, sizeof(ubyte), imageSize, fp);                                                     // 파일에서 원본 이미지 읽어서 inimg에 저장

    fclose(fp);                                                                                     // 파일 닫기


    //for (y = 0; y < bmpInfoHeader.biHeight; y++) {
    //    for (x = 0; x < bmpInfoHeader.biWidth; x++) {
    //            outimg[x + y * bmpInfoHeader.biHeight + 0] = inimg[x + y * bmpInfoHeader.biHeight + 0];
    //            outimg[x + y * bmpInfoHeader.biHeight + 1] = inimg[x + y * bmpInfoHeader.biHeight + 1];
    //            outimg[x + y * bmpInfoHeader.biHeight + 2] = inimg[x + y * bmpInfoHeader.biHeight + 2];
    //        }
    //    }
    //}
    for (int n = 0; n < bmpInfoHeader.biHeight * bmpInfoHeader.biWidth * elemSize; n++)
    {
        outimg[n + 0] = inimg[n + 0];
        outimg[n + 1] = inimg[n + 1];
        outimg[n + 2] = inimg[n + 2];
    }


    /***** write bmp *****/
    if ((fp = fopen(argv[2], "wb")) == NULL) {                                                      // 쓰기용 파일 오픈
        fprintf(stderr, "Error : Failed to open file...?n");
        return -1;
    }
    bmpHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(ubyte) * 256;

    /* BITMAPFILEHEADER 구조체의 데이터 */
    fwrite(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);                                            // 파일헤더 파일에 저장

    /* BITMAPINFOHEADER 구조체의 데이터 */
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);                                        // 인포헤더 파일에 저장
    fwrite(&palrgb, sizeof(ubyte), 256, fp);

    //fwrite(inimg, sizeof(ubyte), imageSize, fp); 
    fwrite(outimg, sizeof(ubyte), imageSize, fp);                                                   // 출력 이미지 파일에 저장

    fclose(fp);                                                                                     // 파일 닫기

    free(inimg);
    free(outimg);

    return 0;
}
