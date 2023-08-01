all: http_server client

http_server: http_server.c
	gcc -W -Wall -lpthread -o server http_server.c

client: simpleclient.c
	g++ -std=c++11 -o client simpleclient.c

clean:
	rm server client

.SILENT: client http_server
