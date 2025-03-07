#include "CLIEngine/widgets/choices.hpp"

int main()
{
    CLIEngine::Sprite spriteC{
        {
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    "
        },
        {
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    "
        },
        {
            "RRRRRRRRRRRRRRRRRRRR",
            "RR                RR",
            "R    RRRRRRRRRRR   R",
            "R   RRRRRRRRRRRRRRRR",
            "R   RRRRRRRRRRRRRRRR",
            "R   RRRRRRRRRRRRRRRR",
            "R    RRRRRRRRRRR   R",
            "RR                RR",
            "RRRRRRRRRRRRRRRRRRRR",
        }
    };
    CLIEngine::Sprite spriteL{
        {
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    "
        },
        {
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    "
        },
        {
            "BBBBBBBBBBBBBBBBBBBB",
            "BB    BBBBBBBBBBBBBB",
            "BB    BBBBBBBBBBBBBB",
            "BB    BBBBBBBBBBBBBB",
            "BB    BBBBBBBBBBBBBB",
            "BB    BBBBBBBBBBBBBB",
            "BB    BBBBBBBBBBBBBB",
            "BB                BB",
            "BBBBBBBBBBBBBBBBBBBB",
        }
    };
    CLIEngine::Sprite spriteI{
        {
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    "
        },
        {
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    "
        },
        {
            "GGGGGGGGGGGGGGGGGGGG",
            "GGG              GGG",
            "GGGGGGGG    GGGGGGGG",
            "GGGGGGGG    GGGGGGGG",
            "GGGGGGGG    GGGGGGGG",
            "GGGGGGGG    GGGGGGGG",
            "GGGGGGGG    GGGGGGGG",
            "GGG              GGG",
            "GGGGGGGGGGGGGGGGGGGG",
        }
    };

    CLIEngine::Choices<std::string> choices{
        CLIEngine::Key::RIGHT,
        CLIEngine::Key::LEFT,
        CLIEngine::Key::SELECT
    };

    choices.add("'Command' C  ", {0, 0}, spriteC, {{}, {}, {}});
    choices.add("'Line' L     ", {0, 0}, spriteL, {{}, {}, {}});
    choices.add("'Interface' I", {0, 0}, spriteI, {{}, {}, {}});

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