#include <Windows.h>
#include "hooft.h"
void window() {
    HWND console = GetConsoleWindow();
    SetWindowPos(console, NULL, 0, 0, 500, 200, NULL);
    CONSOLE_FONT_INFOEX text;
    text.cbSize = sizeof(text);
    text.dwFontSize.X = 20;
    text.dwFontSize.Y = 40;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &text);
}
