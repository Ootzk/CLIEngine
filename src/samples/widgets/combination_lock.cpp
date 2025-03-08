#include "CLIEngine/assets/numbers.hpp"
#include "CLIEngine/widgets/choices.hpp"

int main()
{
    CLIEngine::Choices<std::shared_ptr<CLIEngine::Choices<intP>>> lock{
        CLIEngine::Key::RIGHT, CLIEngine::Key::LEFT, CLIEngine::Key::SELECT
    };
    for (intP d = 0; d < 4; ++d) {
        std::shared_ptr<CLIEngine::Choices<intP>> digit = std::make_shared<CLIEngine::Choices<intP>>(
            CLIEngine::Key::UP, CLIEngine::Key::DOWN, CLIEngine::Key::SELECT
        );
        for (intP i = 0; i < 10; ++i) {
            digit->add(i, {10 * d + 1, 2}, CLIEngine::Assets::numbers_8x5_font1[i], {{}, {}, {}});
        }
        
        lock.add(
            digit,
            {10 * d, 1},
            {
                {
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          "
                },
                {
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          "
                },
                {
                    "GGGGGGGGGG",
                    "G        G",
                    "G        G",
                    "G        G",
                    "G        G",
                    "G        G",
                    "GGGGGGGGGG"
                }
            },
            {
                {
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          "
                },
                {
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          ",
                    "          "
                },
                {
                    "XXXXXXXXXX",
                    "X        X",
                    "X        X",
                    "X        X",
                    "X        X",
                    "X        X",
                    "XXXXXXXXXX"
                }
            }
        );
    }

    std::vector<intP> password{0, 0, 0, 0};
    
    std::cout << "Set your password (4 digit): ";
    
    intP input;
    std::cin >> input;
    if (input < 0 || input > 9999) {
        throw std::runtime_error("password should 4 digit integer.");
    }
    for (int d = 3; d >= 0; --d) {
        password[d] = input % 10;
        input /= 10;
    }

    for (intP index = lock.index(); index < lock.size(); ++index) {
        lock.get()->draw();
        ++lock;
    }
    
    std::vector<intP> trial{0, 0, 0, 0};
    CLIEngine::moveCursor({0, 8});
    std::cout << "Current trial: " << trial[0] << trial[1] << trial[2] << trial[3];

    while (true) {
        auto digit = lock.input(CLIEngine::getKey());
        lock.draw();

        if (digit.has_value()) { // digit selected
            while (true) {
                auto number = digit.value()->input(CLIEngine::getKey());
                digit.value()->draw();
                if (number.has_value()) {
                    trial[lock.index()] = number.value();
                    CLIEngine::moveCursor({0, 8});
                    std::cout << "Current trial: " << trial[0] << trial[1] << trial[2] << trial[3];
                    break;
                }
            }
        }

        if (password == trial) {
            CLIEngine::moveCursor({0, 9});
            std::cout << "You solved password!";
            break;
        }
    }
}