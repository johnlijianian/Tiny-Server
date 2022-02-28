run: server.o client.o
	./server.o
	./client.o
server.o: server.cpp
	g++ server.cpp -o server.o
client.o: client.cpp
	g++ client.cpp -o client.o
clean:
	rm server.o client.o