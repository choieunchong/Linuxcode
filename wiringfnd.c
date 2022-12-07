#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int fndControl(int num)
{
		int i;
		int gpiopins[7] ={2,4,1,16,15,5,8};

		int number[2][7] ={{1,1,1,1,1,1,0},
						{0,1,1,0,0,0,0}};

		for(i =0; i<7; i++){
				pinMode(gpiopins[i], OUTPUT);
		}
		for(i =0; i<7; i++){
				digitalWrite(gpiopins[i], number[num][i]?HIGH:LOW);
		}
		getchar();

		for(i =0; i <7; i++){
				digitalWrite(gpiopins[i], HIGH);
		}
		return 0;
}

int main(int argc, char **argv)
{
		int no;

		no = atoi(argv[1]);
		wiringPiSetup();
		fndControl(no);

		return 0;
}
				


