#include "draw.h"

DrawObject::DrawObject(std::string path)
{
    this->path = path;
}

void DrawObject::draw(std::string name)
{
    std::string line;
    std::ifstream file(path);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
};

