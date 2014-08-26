override PROJECT_ROOT=${shell pwd}
export PROJECT_ROOT

build/libalux.a: build/objects
	make -C link/$(TARGET_ARCH)

build/objects: build dependencies
	mkdir build/objects
	../dependencies/makemaker/bin/makemaker build.coffee
	make -C build/objects

dependencies:
	mkdir dependencies
	git clone http://github.com/unixpickle/ansa.git dependencies/ansa

build:
	mkdir build

clean:
	rm -rf build

clean-all:
	rm -rf dependencies
	rm -rf build
