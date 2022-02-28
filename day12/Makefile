run: server.o client.o ThreadPoolTest.o test.o
server.o: server.cpp
	g++ server.cpp \
	-pthread \
	src/util.cpp src/Epoll.cpp src/InetAddress.cpp src/Socket.cpp src/Connection.cpp \
	src/Channel.cpp src/EventLoop.cpp src/Server.cpp src/Acceptor.cpp src/Buffer.cpp \
	src/ThreadPool.cpp \
	-o server.o
client.o: client.cpp
	g++ src/util.cpp src/Buffer.cpp src/Socket.cpp src/InetAddress.cpp client.cpp -o client.o
ThreadPoolTest.o: 
	g++ -pthread src/ThreadPool.cpp ThreadPoolTest.cpp -o ThreadPoolTest.o
test.o: 
	g++ src/util.cpp src/Buffer.cpp src/Socket.cpp src/InetAddress.cpp src/ThreadPool.cpp \
	-pthread \
	test.cpp -o test.o
clean:
	rm server.o client.o ThreadPoolTest.o test.o