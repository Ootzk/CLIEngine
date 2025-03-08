#include "CLIEngine/core.hpp"
#include "CLIEngine/widgets/choices.hpp"

class NavigationScreen : public CLIEngine::Screen
{
private:
    CLIEngine::Sprite sprite;
    CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>> choices;

public:
    NavigationScreen(
        const std::string& name,
        CLIEngine::Sprite sprite,
        CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>> choices
    );

    void add_choice(
        std::shared_ptr<CLIEngine::Screen> screen,
        CLIEngine::Coordinate location,
        CLIEngine::Sprite chosen_sprite,
        CLIEngine::Sprite not_chosen_sprite
    );

protected:
    std::optional<std::shared_ptr<CLIEngine::Screen>> input() override;
    void enter(const CLIEngine::ScreenTransition&) override;
    void exit(const CLIEngine::ScreenTransition&) override;
    void draw() override;
    std::optional<CLIEngine::ScreenTransition> update() override;
};