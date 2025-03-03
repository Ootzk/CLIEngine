#include "CLIEngine_core.hpp"

int main()
{
    CLIEngine::Sprite font_colors{
        {
            "BLACK",
            "BLUE",
            "GREEN",
            "CYAN",
            "RED",
            "PURPLE",
            "BROWN",
            "LIGHTGRAY",
            "DARKGRAY",
            "LIGHTBLUE",
            "LIGHTGREEN",
            "LIGHTCYAN",
            "LIGHTRED",
            "LIGHTPURPLE",
            "YELLOW",
            "WHITE"
        },
        {
            "XXXXX",
            "BBBB",
            "GGGGG",
            "CCCC",
            "RRR",
            "PPPPPP",
            "OOOOO",
            "aaaaaaaaa",
            "AAAAAAAA",
            "bbbbbbbbb",
            "gggggggggg",
            "ccccccccc",
            "rrrrrrrr",
            "ppppppppppp",
            "YYYYYY",
            "WWWWW"
        },
        {
            "WWWWW", // cuz black font will not shown in black background;
            "    ",
            "     ",
            "    ",
            "   ",
            "      ",
            "     ",
            "         ",
            "        ",
            "         ",
            "          ",
            "         ",
            "        ",
            "           ",
            "      ",
            "     "
        },
    };

    CLIEngine::Sprite background_colors{
        {
            "BLACK",
            "BLUE",
            "GREEN",
            "CYAN",
            "RED",
            "PURPLE",
            "BROWN",
            "LIGHTGRAY",
            "DARKGRAY",
            "LIGHTBLUE",
            "LIGHTGREEN",
            "LIGHTCYAN",
            "LIGHTRED",
            "LIGHTPURPLE",
            "YELLOW",
            "WHITE"
        },
        {
            "     ",
            "    ",
            "     ",
            "    ",
            "   ",
            "      ",
            "     ",
            "         ",
            "        ",
            "         ",
            "          ",
            "         ",
            "        ",
            "           ",
            "      ",
            "XXXXX"  // cuz white font will not shown in white background;
        },
        {
            "XXXXX",
            "BBBB",
            "GGGGG",
            "CCCC",
            "RRR",
            "PPPPPP",
            "OOOOO",
            "aaaaaaaaa",
            "AAAAAAAA",
            "bbbbbbbbb",
            "gggggggggg",
            "ccccccccc",
            "rrrrrrrr",
            "ppppppppppp",
            "YYYYYY",
            "WWWWW"
        }
    };

    while (true) {
        font_colors.draw();
        background_colors.draw({16, 0});
    }
}