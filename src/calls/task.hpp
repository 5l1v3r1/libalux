#ifndef __LIBALUX_TASK_HPP__
#define __LIBALUX_TASK_HPP__

#include <cstdint>
#include <ansa/macros>

namespace libalux {

/**
 * Terminate the current task. If [status] is non-zero, the task will be killed
 * with an "aborted" status.
 */
void Exit(int status) ANSA_NORETURN;

/**
 * Return the process identifier of the current task.
 */
uint32_t GetPid();

}

#endif
