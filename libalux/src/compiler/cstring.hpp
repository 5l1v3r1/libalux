#ifndef __LIBALUX_CSTRING_HPP__
#define __LIBALUX_CSTRING_HPP__

#include <cstddef> // to get size_t type

extern "C" {

void * memcpy(void * dst, const void * src, size_t n);
void * memset(void * b, int c, size_t len);

}

#endif
