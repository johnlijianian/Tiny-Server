run: server.o client.o
server.o: server.cpp
	g++ server.cpp \
	-pthread \
	src/util.cpp src/Epoll.cpp src/InetAddress.cpp src/Socket.cpp src/Connection.cpp \
	src/Channel.cpp src/EventLoop.cpp src/Server.cpp src/Acceptor.cpp src/Buffer.cpp \
	src/ThreadPoll.cpp \
	-o server.o
client.o: client.cpp
	g++ src/util.cpp src/Buffer.cpp src/Socket.cpp src/InetAddress.cpp client.cpp -o client.o
clean:
	rm server.o client.o