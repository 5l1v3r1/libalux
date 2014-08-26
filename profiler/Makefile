OUTPUT_FORMAT ?= binary

override PROJECT_ROOT=${shell pwd}
export PROJECT_ROOT

build/profiler: build/objects
	$(LD)  build/objects/*.o --whole-archive ../libentry/build/libentry.a ../libalux/build/libalux.a -T ../link-scripts/$(TARGET_ARCH)/script.ld --oformat=$(OUTPUT_FORMAT) -o build/profiler

build/objects: build
	mkdir build/objects
	../dependencies/makemaker/bin/makemaker build.coffee
	make -C build/objects

build:
	mkdir build

clean:
	rm -rf build
