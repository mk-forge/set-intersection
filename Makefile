CC=g++
CFLAGS=-g -Werror=vla -I src

NAME=set_intersection
TEST_NAME=test_intersection

all: $(NAME)

$(NAME): src/main.cpp
	$(CC) $(CFLAGS) -o $(NAME) src/main.cpp src/file_io.cpp src/algorithms.cpp src/intersection.cpp

test: $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): tests/test_intersection.cpp
	$(CC) $(CFLAGS) -o $(TEST_NAME) tests/test_intersection.cpp src/file_io.cpp src/algorithms.cpp src/intersection.cpp

clean:
	$(eval SHELL := cmd)
	del *.exe 2>nul