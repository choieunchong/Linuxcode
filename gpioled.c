#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int ledControl(int gpio)
{
		int fd;
		char buf[BUFSIZ];

		fd = open("/sys/class/gpio/export", O_WRONLY);
		sprintf(buf, "%d", gpio);
		write(fd, buf, strlen(buf));
		close(fd);

		sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
		fd = open(buf, O_WRONLY);
		write(fd, "out", 4);
		close(fd);

		char value;
		sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
		fd = open(buf, O_WRONLY);
		read(fd, &value, 1);
		if(value == '0'){
				write(fd,"1",2);
		}else{
				write(fd,"0",2);
		}
		close(fd);
		getchar();

		fd = open("/sys/class/gpio/unexport", O_WRONLY);
		sprintf(buf, "%d", gpio);
		write(fd, buf, strlen(buf));
		close(fd);

		return 0;
}

int main(int argc, char **argv)
{
		int gno;

		if(argc < 2) {
				printf("Usage : %s GPIO_NO\n", argv[0]);
				return -1;
		}
		gno = atoi(argv[1]);
		printf("%d",gno);
		ledControl(gno);

		return 0;
}
