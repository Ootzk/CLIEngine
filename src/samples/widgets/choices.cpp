#include "CLIEngine/assets/logo.hpp"
#include "CLIEngine/widgets/choices.hpp"

int main()
{
    CLIEngine::Choices<std::string> choices{
        CLIEngine::Key::RIGHT,
        CLIEngine::Key::LEFT,
        CLIEngine::Key::SELECT
    };

    choices.add("'Command' C  ", {0, 0}, CLIEngine::Assets::sprite_logo_C, {{}, {}, {}});
    choices.add("'Line' L     ", {0, 0}, CLIEngine::Assets::sprite_logo_L, {{}, {}, {}});
    choices.add("'Interface' I", {0, 0}, CLIEngine::Assets::sprite_logo_I, {{}, {}, {}});

    std::string cache{};
    while (true) {
        choices.input(CLIEngine::getKey());
        choices.draw();

        std::string choice = choices.get();
        if (cache != choice) {
            CLIEngine::Sprite sprite{
                {"your choice is " + choice},
                {"               " + std::string(choice.size(), ' ')},
                {"               " + std::string(choice.size(), ' ')}
            };
            sprite.draw({0, 9});
            cache = choice;
        }
    }
    return 0;
}