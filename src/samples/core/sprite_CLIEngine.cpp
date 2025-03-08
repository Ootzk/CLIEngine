#include "CLIEngine/core.hpp"
#include "CLIEngine/assets/logo.hpp"

int main()
{
    while (true) {
        CLIEngine::Assets::sprite_logo.draw();
        Sleep(1000); // update every 1000ms = 1s
    }
}