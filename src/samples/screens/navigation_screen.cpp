#include "CLIEngine/assets/logo.hpp"
#include "CLIEngine/screens/navigation_screen.hpp"

int main()
{
    CLIEngine::Sprite spriteMenu{
        {
            "      <sample>      ",
            "  navigation_screen ",
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

    auto menu = std::make_shared<NavigationScreen>("Menu", spriteMenu, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto C = std::make_shared<NavigationScreen>("Screen_C", CLIEngine::Assets::sprite_logo_C, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto L = std::make_shared<NavigationScreen>("Screen_L", CLIEngine::Assets::sprite_logo_L, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto I = std::make_shared<NavigationScreen>("Screen_I", CLIEngine::Assets::sprite_logo_I, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});

    menu->add_choice(
        C,
        CLIEngine::Coordinate{8, 5},
        CLIEngine::Sprite{{"> C <"}, {"RRRRR"}, {"     "}},
        CLIEngine::Sprite{{"  C  "}, {"RRRRR"}, {"     "}}
    );
    menu->add_choice(
        L,
        CLIEngine::Coordinate{8, 6},
        CLIEngine::Sprite{{"> L <"}, {"BBBBB"}, {"     "}},
        CLIEngine::Sprite{{"  L  "}, {"BBBBB"}, {"     "}}
    );
    menu->add_choice(
        I,
        CLIEngine::Coordinate{8, 7},
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