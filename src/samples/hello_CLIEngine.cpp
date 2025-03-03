#include "CLIEngine/core.hpp"

int main()
{
    // set terminal color theme with blue character and yellow background
    CLIEngine::setPalette(CLIEngine::Color::BLUE, CLIEngine::Color::YELLOW);
    std::cout << "Hello CLIEngine!";

    // reset default terminal color theme; white character and black background
    CLIEngine::setPalette();
    std::cout << " ";

    // set terminal color theme with red character and green background
    CLIEngine::setPalette(CLIEngine::Color::RED, CLIEngine::Color::GREEN);
    std::cout << "This is the sample code which changes the terminal color theme!" << std::endl << std::endl;

    // reset default terminal color theme; white character and black background
    CLIEngine::setPalette();

    return 0;
}