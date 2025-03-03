#include "CLIEngine_screen.hpp"

namespace CLIEngine {

Screen::Screen(const std::string& name) : name(name)
{
}

void Screen::clear()
{
    system("cls");
}

void Screen::wait()
{
    Sleep(1000 / FPS);
}

ScreenTransition Screen::loop(const ScreenTransition& previous)
{
    this->enter(previous);

    std::optional<ScreenTransition> future = std::nullopt;
    while (!future.has_value()) {
        future = this->update();
    }

    this->exit(future.value());

    return future.value();
}

} // end of CLIEngine namespace