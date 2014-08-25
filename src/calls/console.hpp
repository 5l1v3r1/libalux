#ifndef __LIBALUX_CONSOLE_HPP__
#define __LIBALUX_CONSOLE_HPP__

namespace libalux {

/**
 * Print some [text] to the global console. In the future, output will be
 * facilitated by an IPC mechanism.
 */
void PrintConsole(const char * text);

}

#endif
