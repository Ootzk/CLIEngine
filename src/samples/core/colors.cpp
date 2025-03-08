#include "CLIEngine/assets/palette.hpp"
#include "CLIEngine/core.hpp"

int main()
{
    SMALL_RECT windowSize = { 0, 0, 100, 256 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &windowSize);

    CLIEngine::Assets::palette.draw();
    for (intP y = 0; y < 256; ++y) {
        auto [f, b] = CLIEngine::getPalette({0, y});
        CLIEngine::moveCursor({12, y});
        CLIEngine::setPalette(f, b);
        std::cout << "font color: " << CLIEngine::Color2str(f) << " / " << "background color: " << CLIEngine::Color2str(b);
        CLIEngine::setPalette();
    }
    while(true) {}
}