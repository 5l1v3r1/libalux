#include <libalux/print>

using namespace libalux;

void TestColors() {
  Print("this should be ");
  SetColor(ColorBlue, true);
  Print("bl");
  SetColor(ColorBlue, false);
  Print("ue ");
  SetColor(ColorGreen, true);
  Print("gre");
  SetColor(ColorGreen, false);
  Print("en ");
  SetColor(ColorCyan, true);
  Print("cy");
  SetColor(ColorCyan, false);
  Print("an ");
  SetColor(ColorRed, true);
  Print("re");
  SetColor(ColorRed, false);
  Print("d ");
  SetColor(ColorMagenta, true);
  Print("mage");
  SetColor(ColorMagenta, false);
  Print("nta ");
  SetColor(ColorBrown, true);
  Print("bro");
  SetColor(ColorBrown, false);
  Print("wn");
  SetColor(ColorLightGray, false);
  PrintLine("!");
  SetColor(ColorLightGray, true);
}