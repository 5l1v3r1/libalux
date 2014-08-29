#ifndef __LIBALUX_THREAD_HPP__
#define __LIBALUX_THREAD_HPP__

#include <cstdint>
#include <cstddef>
#include <ansa/macros>

namespace libalux {

/**
 * Exit the current thread. This will never exit the owning task, even if this
 * is the task's last thread. Thus, you should take care only to call this
 * method from worker/helper threads to avoid empty tasks.
 */
void ExitThread() ANSA_NORETURN;

/**
 * Return this thread's identifier. The main thread will have thread identifier
 * zero. The thread ID is used to wakeup sleeping threads.
 */
uint32_t GetThreadId();

/**
 * Launch a thread and get its thread ID. The created thread will run a given
 * method and pass a specified argument to it.
 *
 * If `true` is returned, a thread was successfully launched. If you pass a
 * non-NULL pointer as [ident], it will be set to the new thread's identifier.
 */
bool LaunchThread(void (*)(void *), void *, uint32_t * ident = NULL);

/**
 * Sleep this current thread until a certain number of nanoseconds have elapsed
 * or until this thread is woken up--whichever happens first. If this thread
 * has been woken up since its last sleep, Sleep() will return immediately.
 *
 * If you pass zero nanoseconds, this method is not guaranteed to return
 * control to other tasks. However, there is a guarantee that such a call will
 * absorb any previous wakeup.
 */
void Sleep(uint64_t nanos);

/**
 * Sleep this thread with an infinite timeout. This will only return when this
 * thread is woken up. If a wakeup has been sent to this thread since it's last
 * sleep, SleepInfinite() will return immediately.
 */
void SleepInfinite();

/**
 * Wakeup a thread given it's identifier.
 */
void Wakeup(uint32_t ident);

}

#endif
