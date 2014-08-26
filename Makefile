TARGET_ARCH ?= x64
export TARGET_ARCH

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

libalux/build/libalux.a: dependencies
	make -C libalux

libentry/build/libentry.a: dependencies
	make -C libentry

profiler/build/profiler: libentry/build/libentry.a libalux/build/libalux.a
	make -C profiler

tester/build/tester: libentry/build/libentry.a libalux/build/libalux.a
	make -C tester

dependencies:
	mkdir dependencies
	git clone http://github.com/unixpickle/makemaker.git dependencies/makemaker

clean:
	cd libalux && make clean && cd -
	cd libentry && make clean && cd -
	cd profiler && make clean && cd -
	cd tester && make clean && cd -

clean-all:
	rm -rf dependencies
	rm -rf build
	cd libalux && make clean-all && cd -
	cd libentry && make clean && cd -
	cd profiler && make clean && cd -
	cd tester && make clean && cd -
