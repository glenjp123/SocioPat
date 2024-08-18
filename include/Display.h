#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>

class Display {
public:
    void col_red(const std::string& s) const;
    void col_green(const std::string& s) const;
    void col_blue(const std::string& s) const;
    void col_yellow(const std::string& s) const;
};

#endif // DISPLAY_H
