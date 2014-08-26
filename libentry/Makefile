override PROJECT_ROOT=${shell pwd}
export PROJECT_ROOT

build/libentry.a: build/objects
	$(AR) crv build/libentry.a build/objects/*.o

build/objects: build
	mkdir build/objects
	../dependencies/makemaker/bin/makemaker build.coffee
	make -C build/objects

build:
	mkdir build

clean:
	rm -rf build
