CC=g++
CFLAGS= -g -Werror=vla

NAME = set_intersection
TEST_NAME = test_intersection

all: $(NAME)

$(NAME): main.cpp
	$(CC) $(CFLAGS) -o $(NAME) main.cpp file_io.cpp algorithms.cpp intersection.cpp

test: $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): test_intersection.cpp
	$(CC) $(CFLAGS) -o $(TEST_NAME) test_intersection.cpp file_io.cpp algorithms.cpp intersection.cpp

clean:
	$(eval SHELL := cmd)
	del *.exe 2>nul