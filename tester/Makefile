OUTPUT_FORMAT ?= binary

override PROJECT_ROOT=${shell pwd}
export PROJECT_ROOT

build/tester: build/objects
	$(LD) build/objects/*.o --whole-archive ../build/libalux.a -T ../link/$(TARGET_ARCH)/app_script.ld --oformat=$(OUTPUT_FORMAT) -o build/tester

build/objects: build
	mkdir build/objects
	../dependencies/makemaker/bin/makemaker build.coffee
	make -C build/objects

build:
	mkdir build

clean:
	rm -rf build
