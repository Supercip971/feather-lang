
CFILES := $(shell find src -type f -name \*.cpp)
HFILES := $(shell find src -type f -name \*.h)
TST_FILES := $(shell find test -type f)
OBJFILES := $(patsubst %.cpp, %.o, $(CFILES))
OUTPUT := "./build/feather"
%.o: %.cpp $(CFILES) $(HFILES)
	@echo "[ C++] building $< "
	@g++ -c -pthread -fpermissive -fsanitize=address -fsanitize=undefined -std=c++20 -m64 -Wall -g -march=x86-64 -I src/ -O3 -msse -o $@ $<

$(OUTPUT): $(OBJFILES)
	@echo "all"
	@g++ $(OBJFILES) -fpermissive -fsanitize=address -fsanitize=undefined -pthread -o build/feather



run: 
	./build/feather
run_test:
	./build/feather $(TST_FILES)
	cat output

test:
	@echo "not implemented for the moment"

format: 
	clang-format -i --style=file $(CFILES) $(HFILES)


clean:
	rm $(OBJFILES)
	rm ./build/feather


all: $(OUTPUT) 
	@make run




