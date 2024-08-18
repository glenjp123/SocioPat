#include "Display.h"

void Display::col_red(const std::string& s) const {
    std::cout << "\033[31m" << s << "\033[0m";
}

void Display::col_green(const std::string& s) const {
    std::cout << "\033[32m" << s << "\033[0m";
}

void Display::col_blue(const std::string& s) const {
    std::cout << "\033[34m" << s << "\033[0m";
}

void Display::col_yellow(const std::string& s) const {
    std::cout << "\033[33m" << s << "\033[0m";
}
