#include "CLIEngine/widgets/dice.hpp"

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
    std::vector<CLIEngine::Sprite> dice_common_sprites{
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
    };
    std::vector<intP> eyes{1, 2, 3, 4, 5, 6};
    std::vector<double> probabilities{1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    CLIEngine::Dice<intP> dice1{
        eyes,
        dice_common_sprites,
        probabilities
    };
    CLIEngine::Dice<intP> dice2{
        eyes,
        dice_common_sprites,
        probabilities
    };

    // Hide Cursor
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);

    std::cout << "Simple dice";
    dice1.draw(CLIEngine::Coordinate{ 0, 2 }, 1);
    dice2.draw(CLIEngine::Coordinate{ 8, 2 }, 1);
    while (true) {
        if (CLIEngine::getKey() == CLIEngine::Key::SELECT) {
            intP eye1 = dice1.roll();
            intP eye2 = dice2.roll();
            
            dice1.draw(CLIEngine::Coordinate{ 0, 2 });
            dice2.draw(CLIEngine::Coordinate{ 8, 2 });

            CLIEngine::moveCursor({ 0, 5 });
            std::cout << "dice 1: " << eye1 << endl;
            std::cout << "dice 2: " << eye2 << endl;
        }
    }
}