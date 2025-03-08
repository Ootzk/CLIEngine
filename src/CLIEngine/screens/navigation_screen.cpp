#include "CLIEngine/screens/navigation_screen.hpp"

NavigationScreen::NavigationScreen(
    const std::string& name,
    CLIEngine::Sprite sprite,
    CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>> choices
) : CLIEngine::Screen{name}, sprite(sprite), choices(choices)
{
}

void NavigationScreen::add_choice(
    std::shared_ptr<CLIEngine::Screen> screen,
    CLIEngine::Coordinate location,
    CLIEngine::Sprite chosen_sprite,
    CLIEngine::Sprite not_chosen_sprite
)
{
    choices.add(screen, location, chosen_sprite, not_chosen_sprite);
}

std::optional<std::shared_ptr<CLIEngine::Screen>> NavigationScreen::input()
{
    return choices.input(CLIEngine::getKey());
}

void NavigationScreen::enter(const CLIEngine::ScreenTransition&)
{
    clear();
    choices.reset();

    sprite.draw();
    choices.draw();
}

void NavigationScreen::exit(const CLIEngine::ScreenTransition&)
{
    choices.reset();
}

void NavigationScreen::draw()
{
    choices.draw();
}

std::optional<CLIEngine::ScreenTransition> NavigationScreen::update()
{
    std::optional<std::shared_ptr<CLIEngine::Screen>> future = input();
    draw();
    wait();

    if (future.has_value()) {
        return CLIEngine::ScreenTransition {
            shared_from_this(),
            future.value(),
            {}
        };
    }
    return std::nullopt;
}