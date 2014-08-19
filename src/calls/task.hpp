#ifndef __LIBALUX_TASK_HPP__
#define __LIBALUX_TASK_HPP__

#include <ansa/macros>

namespace alux {

/**
 * Terminate the current task. If [status] is non-zero, the task will be killed
 * with an "aborted" status.
 */
void Exit(int status) ANSA_NORETURN;

}

#endif
