#include "CLIEngine/choices.hpp"

class ChoosableScreen : public CLIEngine::Screen
{
private:
    CLIEngine::Sprite sprite;
    CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>> choices;

public:
    ChoosableScreen(
        const std::string& name,
        CLIEngine::Sprite sprite,
        CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>> choices
    ) : CLIEngine::Screen{name}, sprite(sprite), choices(choices) {}

    void add_choice(
        std::shared_ptr<CLIEngine::Screen> screen,
        CLIEngine::Coordinate location,
        CLIEngine::Sprite chosen_sprite,
        CLIEngine::Sprite not_chosen_sprite
    ) {
        choices.add(screen, location, chosen_sprite, not_chosen_sprite);
    }

protected:
    std::optional<std::shared_ptr<CLIEngine::Screen>> input() override {
        return choices.input(CLIEngine::getKey());
    }

    void enter(const CLIEngine::ScreenTransition&) override {
        clear();
        choices.reset_cursor();

        sprite.draw();
        choices.draw();
    }
    void exit(const CLIEngine::ScreenTransition&) override {
        choices.reset_cursor();
    }

    void draw() override {
        choices.draw();
    }

    std::optional<CLIEngine::ScreenTransition> update() override {
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
};

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

    auto menu = std::make_shared<ChoosableScreen>("Menu", spriteMenu, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto C = std::make_shared<ChoosableScreen>("Screen_C", spriteC, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto L = std::make_shared<ChoosableScreen>("Screen_L", spriteL, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});
    auto I = std::make_shared<ChoosableScreen>("Screen_I", spriteI, CLIEngine::Choices<std::shared_ptr<CLIEngine::Screen>>{});

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