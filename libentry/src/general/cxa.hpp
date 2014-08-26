#ifndef __LIBENTRY_CXA_HPP__
#define __LIBENTRY_CXA_HPP__

extern "C" {

extern void * __dso_handle;
 
int __cxa_atexit(void (* destructor) (void *), void * arg, void * dso);
void __cxa_finalize(void * f);

}

#endif
