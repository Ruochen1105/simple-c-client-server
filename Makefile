all: httpd client

httpd: httpd.c
	gcc -W -Wall -lpthread -o server httpd.c

client: simpleclient.c
	g++ -std=c++11 -o client simpleclient.c

clean:
	rm server client

.SILENT: client httpd
