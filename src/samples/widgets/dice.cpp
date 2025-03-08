#include "CLIEngine/assets/numbers.hpp"
#include "CLIEngine/widgets/dice.hpp"

CLIEngine::Dice<intP> make_dice(
    CLIEngine::Color eyecolor,
    CLIEngine::Color bodycolor
)
{
    std::vector<intP> eyes{ 1, 2, 3, 4, 5, 6 };
    auto sprites = CLIEngine::Assets::sprites_diceeyes_7x3;
    std::vector<double> probs{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    auto dice = CLIEngine::Dice<intP>(eyes, sprites, probs);
    dice.changeFontColor(CLIEngine::Color::BLACK, eyecolor);
    dice.changeBackColor(CLIEngine::Color::WHITE, bodycolor);
    return dice;
}

int main()
{
    std::vector<CLIEngine::Dice<intP>> dices;
    dices.emplace_back(make_dice(CLIEngine::Color::RED, CLIEngine::Color::WHITE));
    dices.emplace_back(make_dice(CLIEngine::Color::BLACK, CLIEngine::Color::LIGHTPURPLE));
    dices.emplace_back(make_dice(CLIEngine::Color::CYAN, CLIEngine::Color::YELLOW));
    dices.emplace_back(make_dice(CLIEngine::Color::WHITE, CLIEngine::Color::DARKGRAY));
    dices.emplace_back(make_dice(CLIEngine::Color::PURPLE, CLIEngine::Color::LIGHTGREEN));

    // Hide Cursor
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);

    std::cout << "Simple dice";

    const intP width = (7 + 1); // numbers_diceeye_7x3;
    for (intP i = 0; i < 5; ++i) {
        dices[i].roll();
        dices[i].draw({ width * i, 2 }, 1); // at first eyes are all 1.
    }

    while (true) {
        if (CLIEngine::getKey() == CLIEngine::Key::SELECT) {
            intP sum = 0;
            for (intP i = 0; i < 5; ++i) {
                sum += dices[i].roll();
                dices[i].draw({ width * i, 2 });
            }

            std::stringstream ss;
            ss << std::left << std::setw(2) << std::setfill(' ') << std::to_string(sum);

            CLIEngine::Sprite result{
                {"sum: " + ss.str()},
                {"       "},
                {"       "}
            };
            result.draw({ 0, 5 });
        }
    }
}