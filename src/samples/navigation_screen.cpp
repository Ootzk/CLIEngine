#include "CLIEngine/screens/navigation_screen.hpp"

int main()
{
    CLIEngine::Sprite spriteMenu{
        {
            "      <sample>      ",
            " CLIEngine::Choices ",
            "                    ",
            "    choice screen   ",
            "                    ",
            "          C         ",
            "          L         ",
            "          I         ",
            "                    ",
            "                    "
        },
        {
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "                    ",
            "          R         ",
            "          B         ",
            "          G         ",
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
            "                    ",
            "                    "
        }
    };
    CLIEngine::Sprite spriteC{
        {
            " space bar: go back ",
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
            "                    ",
            "                    "
        },
        {
            "                    ",
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
            " space bar: go back ",
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
            "                    ",
            "                    "
        },
        {
            "                    ",
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
            " space bar: go back ",
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
            "                    ",
            "                    "
        },
        {
            "                    ",
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

    auto menu = std::make_shared<NavigationScreen>("Menu", spriteMenu, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto C = std::make_shared<NavigationScreen>("Screen_C", spriteC, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto L = std::make_shared<NavigationScreen>("Screen_L", spriteL, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto I = std::make_shared<NavigationScreen>("Screen_I", spriteI, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});

    menu->add_choice(
        C,
        CLIEngine::Coordinate{4, 5},
        CLIEngine::Sprite{{"> C <"}, {"RRRRR"}, {"     "}},
        CLIEngine::Sprite{{"  C  "}, {"RRRRR"}, {"     "}}
    );
    menu->add_choice(
        L,
        CLIEngine::Coordinate{4, 6},
        CLIEngine::Sprite{{"> L <"}, {"BBBBB"}, {"     "}},
        CLIEngine::Sprite{{"  L  "}, {"BBBBB"}, {"     "}}
    );
    menu->add_choice(
        I,
        CLIEngine::Coordinate{4, 7},
        CLIEngine::Sprite{{"> I <"}, {"GGGGG"}, {"     "}},
        CLIEngine::Sprite{{"  I  "}, {"GGGGG"}, {"     "}}
    );
    C->add_choice(
        menu,
        CLIEngine::Coordinate{0, 0},
        CLIEngine::Sprite{{}, {}, {}},
        CLIEngine::Sprite{{}, {}, {}}
    );
    L->add_choice(
        menu,
        CLIEngine::Coordinate{0, 0},
        CLIEngine::Sprite{{}, {}, {}},
        CLIEngine::Sprite{{}, {}, {}}
    );
    I->add_choice(
        menu,
        CLIEngine::Coordinate{0, 0},
        CLIEngine::Sprite{{}, {}, {}},
        CLIEngine::Sprite{{}, {}, {}}
    );

    std::shared_ptr<CLIEngine::Screen> current = menu;
    CLIEngine::ScreenTransition msg = { current, current, {} };
    while (true) {
        msg = current->loop(msg);
        current = msg.to;
    }
    return 0;
}