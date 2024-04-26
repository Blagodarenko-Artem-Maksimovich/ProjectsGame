#include "visual.h"

void draw(std::string filename)
{
    std::string line;
    std::ifstream file(filename);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
}

void typewriter(std::string str)
{
    for (int i = 0; i <= str.length() - 1; i++)
    {
        std::cout << str[i];
        Sleep(50);
    }
    std::cout << std::endl;
}