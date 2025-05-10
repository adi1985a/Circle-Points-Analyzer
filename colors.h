#pragma once
#include <windows.h>
#include <string>

namespace Colors {
    enum Code {
        CYAN = 11,
        GREEN = 10,
        YELLOW = 14,
        WHITE = 15,
        MAGENTA = 13
    };

    void setColor(Code code) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, code);
    }

    void drawLine(char symbol = '-', int length = 50) {
        std::string line(length, symbol);
        std::cout << line << std::endl;
    }
}
