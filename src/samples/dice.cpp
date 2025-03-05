#include "CLIEngine/dice.hpp"

int main()
{
    std::vector<std::string> dice_common_fontcolors{
        {
            "RRRRRRR",
            "RRRRRRR",
            "RRRRRRR"
        }
    };
    std::vector<std::string> dice_common_backgroundcolors{
        {
            "WWWWWWW",
            "WWWWWWW",
            "WWWWWWW"
        }
    };

    CLIEngine::Dice dice{
        {"1", "2", "3", "4", "5", "6"},
        {
            {
                {
                    "       ",
                    "   *   ",
                    "       "
                },
                dice_common_fontcolors,
                dice_common_backgroundcolors
            },
            {
                {
                    "       ",
                    " *   * ",
                    "       "
                },
                dice_common_fontcolors,
                dice_common_backgroundcolors
            },
            {
                {
                    "   *   ",
                    "   *   ",
                    "   *   ",
                },
                dice_common_fontcolors,
                dice_common_backgroundcolors
            },
            {
                {
                    " *   * ",
                    "       ",
                    " *   * "
                },
                dice_common_fontcolors,
                dice_common_backgroundcolors
            },
            {
                {
                    " *   * ",
                    "   *   ",
                    " *   * "
                },
                dice_common_fontcolors,
                dice_common_backgroundcolors
            },
            {
                {
                    " *   * ",
                    " *   * ",
                    " *   * "
                },
                dice_common_fontcolors,
                dice_common_backgroundcolors
            }
        },
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0}
    };

    // Hide Cursor
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);

    std::cout << "Simple dice";
    while (true) {
        dice.draw(CLIEngine::Coordinate{ 0, 2 });

        if (CLIEngine::getKey() == CLIEngine::Key::SELECT) {
            dice.roll();
            dice.draw(CLIEngine::Coordinate{ 0, 2 });
        }
    }
}