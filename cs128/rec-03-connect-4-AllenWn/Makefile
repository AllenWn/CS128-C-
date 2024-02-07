CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -Werror -O0 -gdwarf-4 -fsanitize=address,undefined,implicit-conversion,local-bounds -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize-address-use-after-return=always

exec: bin/exec

bin/exec: ./src/driver.cc ./includes/board.hpp ./src/board.cc ./includes/space.hpp ./src/space.cc
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/board.cc ./src/space.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -rf bin/*
