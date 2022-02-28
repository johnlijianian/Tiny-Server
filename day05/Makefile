run: server.o client.o
server.o: server.cpp
	g++ util.cpp server.cpp Epoll.cpp InetAddress.cpp Socket.cpp Channel.cpp -o server.o
client.o: client.cpp
	g++ util.cpp client.cpp -o client.o
clean:
	rm server.o client.o