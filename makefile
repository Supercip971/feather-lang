
CFILES := $(shell find src -type f -name \*.cpp)
HFILES := $(shell find src -type f -name \*.h)

OBJFILES := $(patsubst %.cpp, %.o, $(CFILES))

%.o: %.cpp $(CFILES) $(HFILES)
	@echo "[ C++] building $< "
	@g++ -c -pthread -fpermissive -fsanitize=address -fsanitize=undefined -std=c++20 -m64 -Wall -g -march=x86-64 -I src/ -O3 -msse -o $@ $<

link: $(OBJFILES)
	@echo "all"
	@g++ $(OBJFILES) -fpermissive -fsanitize=address -fsanitize=undefined -pthread -o build/feather



run: 
	./build/feather


test:
	@echo "not implemented for the moment"

format: 
	clang-format -i --style=file $(CFILES) $(HFILES)


clean:
	rm $(OBJFILES)
	rm ./build/feather


all: $(OBJFILES) 
	@make format
	@make link
	@make run




