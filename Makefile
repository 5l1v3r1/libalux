TARGET_ARCH ?= x64
override PROJECT_ROOT=${shell pwd}

export TARGET_ARCH
export PROJECT_ROOT

CC ?= gcc
CXX ?= g++
ASM ?= nasm
CXXFLAGS ?= -nostdlib -nostdinc -ffreestanding -fno-exceptions -fno-rtti -Wno-long-long -Wall -Wextra -std=c++11 -mno-sse -mno-mmx -fno-stack-protector -fno-builtin -mcmodel=large
CFLAGS ?= -nostdlib -nostdinc -ffreestanding -Wno-long-long -Wall -Wextra -mno-sse -mno-mmx -fno-stack-protector -fno-builtin -mcmodel=large
ASMFLAGS ?= -f elf64

export CC
export CXX
export ASM
export CXXFLAGS
export CFLAGS
export ASMFLAGS

default: build/libalux.a

profiler/build/profiler: build/libalux.a
	make -C profiler

tester/build/tester: build/libalux.a
	make -C tester

build/libalux.a: build/objects
	make -C link/$(TARGET_ARCH)

build/objects: build dependencies
	mkdir build/objects
	./dependencies/makemaker/bin/makemaker build.coffee
	make -C build/objects

dependencies:
	mkdir dependencies
	git clone http://github.com/unixpickle/ansa.git dependencies/ansa
	git clone http://github.com/unixpickle/makemaker.git dependencies/makemaker

build:
	mkdir build

clean:
	rm -rf build
	cd profiler && make clean && cd -
	cd tester && make clean && cd -
