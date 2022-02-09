CC = g++ -std=c++11

all: Goodreads.out

Goodreads.out: main.o functions.o Author.o Book.o User.o Review.o FollowEdges.o Goodreads.o
	${CC} main.o functions.o Author.o Book.o User.o Review.o FollowEdges.o Goodreads.o -o Goodreads.out

main.o: main.cpp functions.hpp Author.hpp Book.hpp User.hpp Review.hpp FollowEdges.hpp Goodreads.hpp
	${CC} -c main.cpp

functions.o: functions.cpp functions.hpp Author.hpp Book.hpp User.hpp Review.hpp FollowEdges.hpp Goodreads.hpp
	${CC} -c functions.cpp

Author.o: Author.cpp Author.hpp
	${CC} -c Author.cpp

Book.o: Book.cpp Book.hpp Author.hpp
	${CC} -c Book.cpp

User.o: User.cpp User.hpp Author.hpp Book.hpp
	${CC} -c User.cpp 

Review.o: Review.cpp Review.hpp Book.hpp User.hpp
	${CC} -c Review.cpp

FollowEdges.o: FollowEdges.cpp FollowEdges.hpp User.hpp
	${CC} -c FollowEdges.cpp

Goodreads.o: Goodreads.cpp Goodreads.hpp Author.hpp Book.hpp User.hpp Review.hpp FollowEdges.hpp
	${CC} -c Goodreads.cpp

clean:
	rm *.o
	rm Goodreads.out
