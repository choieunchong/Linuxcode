#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h>


#define TCP_PORT 5100

int main(int argc, char **argv)
{
		int shutdown(int sockfd, int how);
		int ssock;
		struct sockaddr_in servaddr;
		char mesg[BUFSIZ];
		fd_set readfd;
		
		connect_fd = socket(AF_INET, SOCK_STREAM, 0);
		if(connect_fd == -1){
		perror("socket Contruction Error\n");
		return -1;
		}

		connect.addr.sin_family = AF_INET;
		connect.addr.sinport = htons(atoi(argv[2]));
		connect_addr.sin_addr.s_addr = inet_addr(argv[1]);

		if(connect(connect_fd,(struct sockaddr*)&connect_addr, sizeof
				 (connect_addr) )== -1){
				perror("connecting Error\n");
				return -1;
		}
		
		FD_ZERO(&readfd);
		while(1){
		FD_SET(0, &readfd);
		FD_SET(connet_fd, &readfd);

		select(connect_fd+1, &readfd, NULL,NULL, NULL);

	
		if(argc < 2) {
				printf("Usage : %s IP_ADDRESS\n" ,argv[0]);
				return -1;
		}

		if((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
				perror("socket()");
				return -1;
		}

		memset(&servaddr, 0, sizeof(servaddr));
		servaddr.sin_family = AF_INET;

		inet_pton(AF_INET, argv[1], &(servaddr. sin_addr.s_addr));
		servaddr.sin_port = htons(TCP_PORT);

		if(connect(ssock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
				perror("connect()");
				return -1;
		}
		fgets(mesg, BUFSIZ, stdin);
		if(send(ssock, mesg, BUFSIZ, MSG_DONTWAIT) <= 0){
				perror("send()");
				return -1;
		}
		shutdown(ssock, SHUT_WR);

		memset(mesg, 0, BUFSIZ);
		if(recv(ssock, mesg, BUFSIZ, 0) <= 0){
				perror("recv()");
				return -1;
		}

		shutdown(ssock, SHUT_RD);

		printf("Received data : %s " , mesg);

		close(ssock);

		return 0;
}
