#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <iostream>

int main(int argc, char *argv[])
{
 int sockfd;
 int len;
 struct sockaddr_in address;
 int result;

 char request[0xfff], response[0xfff];
 strcpy(request, "A");

 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 address.sin_family = AF_INET;
 address.sin_addr.s_addr = inet_addr("127.0.0.1");
 address.sin_port = htons(4321);
 len = sizeof(address);

 auto start_wall_clock = std::chrono::steady_clock::now();
 result = connect(sockfd, (struct sockaddr *)&address, len);

 if (result == -1)
 {
  perror("oops: client1");
  exit(1);
 }
 send(sockfd, &request, 1, 0);
 recv(sockfd, &response, 0xfff, 0);
 auto finish_wall_clock = std::chrono::steady_clock::now();
 std::cout << "milliseconds: " << (finish_wall_clock - start_wall_clock) / std::chrono::milliseconds(1) << '\n';
 printf("char from server = %s\n", response);
 close(sockfd);
 exit(0);
}
