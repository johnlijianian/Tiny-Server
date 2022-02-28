run: server.o client.o
server.o: server.cpp
	g++ src/util.cpp server.cpp src/Epoll.cpp src/InetAddress.cpp src/Socket.cpp src/Channel.cpp src/EventLoop.cpp src/Server.cpp src/Acceptor.cpp -o server.o
client.o: client.cpp
	g++ src/util.cpp client.cpp -o client.o
clean:
	rm server.o client.o