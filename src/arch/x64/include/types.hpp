#ifndef __LIBALUX_X64_TYPES_HPP__
#define __LIBALUX_X64_TYPES_HPP__

#include <cstdint>

/**
 * A numerical representation of a physical address.
 */
typedef uint64_t PhysAddr;

/**
 * A numerical representation of the size of a chunk of physical memory.
 */
typedef uint64_t PhysSize;

/**
 * A numerical representation of a virtual address.
 */
typedef uint64_t VirtAddr;

/**
 * A numerical type that is the native size of the processor.
 */
typedef int64_t NativeInt;

/**
 * An unsigned NativeInt
 */
typedef uint64_t NativeUInt;

#endif