#ifndef __LIBALUX_CONSOLE_HPP__
#define __LIBALUX_CONSOLE_HPP__

namespace libalux {

typedef enum {
  ColorBlack = 0,
  ColorBlue = 1,
  ColorGreen = 2,
  ColorCyan = 3,
  ColorRed = 4,
  ColorMagenta = 5,
  ColorBrown = 6,
  ColorLightGray = 7
} Color;

/**
 * Print some [text] to the global console. In the future, output will be
 * facilitated by an IPC mechanism.
 */
void PrintConsole(const char * text);

/**
 * Set the color on the output console.
 */
void SetColor(Color c, bool bright);

}

#endif
