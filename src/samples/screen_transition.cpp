#include "CLIEngine/core.hpp"

using ScreenPtr = std::shared_ptr<CLIEngine::Screen>;

class Screen_Char : public CLIEngine::Screen
{
private:
    CLIEngine::Sprite sprite;
    char message_color;
    ScreenPtr left;
    ScreenPtr right;

public:
    Screen_Char(
        const std::string& name,
        CLIEngine::Sprite sprite,
        char message_color
    ): sprite(sprite), message_color(message_color), CLIEngine::Screen{name}
    {

    }

    void init(ScreenPtr left, ScreenPtr right)
    {
        this->left = left;
        this->right = right;
    }

protected:
    std::optional<std::shared_ptr<Screen>> input() override
    {
        switch (CLIEngine::getKey())
        {
        case CLIEngine::Key::LEFT: { return left; }
        case CLIEngine::Key::RIGHT: { return right; }
        default: { return std::nullopt; }
        }
    }

    void enter(const CLIEngine::ScreenTransition& previous) override
    {
        clear();
        this->sprite.draw();

        CLIEngine::moveCursor();
        CLIEngine::setPalette(CLIEngine::char2Color(this->message_color));
        std::cout << previous.message;
        CLIEngine::setPalette();
    }

    void exit(const CLIEngine::ScreenTransition& future) override
    {
        // do nothing
    }

    void draw() override
    {
        // do nothing because everything drawn in enter step
    }

    std::optional<CLIEngine::ScreenTransition> update() override
    {
        std::optional<ScreenPtr> future = this->input();
        this->draw();
        this->wait();

        if (future.has_value()) {
            return CLIEngine::ScreenTransition{
                shared_from_this(),
                future.value(),
                "transited from " + this->name + " to " + future.value()->name
            };
        }
        return std::nullopt;
    }
};

int main()
{
    CLIEngine::Sprite spriteC{
        {
            "                            ",
            "                            ",
            "                            ",
            "                            ",
            "<-                        ->",
            " I                        L ",
            "                            ",
            "                            ",
            "                            ",
            "                            "
        },
        {
            "                            ",
            "                            ",
            "                            ",
            "                            ",
            "GG                        BB",
            " G                        B ",
            "                            ",
            "                            ",
            "                            ",
            "                            "
        },
        {
            "                            ",
            "    RRRRRRRRRRRRRRRRRRRR    ",
            "    RR                RR    ",
            "    R    RRRRRRRRRRR   R    ",
            "    R   RRRRRRRRRRRRRRRR    ",
            "    R   RRRRRRRRRRRRRRRR    ",
            "    R   RRRRRRRRRRRRRRRR    ",
            "    R    RRRRRRRRRRR   R    ",
            "    RR                RR    ",
            "    RRRRRRRRRRRRRRRRRRRR    ",
        }
    };
    CLIEngine::Sprite spriteL{
        {
            "                            ",
            "                            ",
            "                            ",
            "                            ",
            "<-                        ->",
            " C                        I ",
            "                            ",
            "                            ",
            "                            ",
            "                            "
        },
        {
            "                            ",
            "                            ",
            "                            ",
            "                            ",
            "RR                        GG",
            " R                        G ",
            "                            ",
            "                            ",
            "                            ",
            "                            "
        },
        {
            "                            ",
            "    BBBBBBBBBBBBBBBBBBBB    ",
            "    BB    BBBBBBBBBBBBBB    ",
            "    BB    BBBBBBBBBBBBBB    ",
            "    BB    BBBBBBBBBBBBBB    ",
            "    BB    BBBBBBBBBBBBBB    ",
            "    BB    BBBBBBBBBBBBBB    ",
            "    BB    BBBBBBBBBBBBBB    ",
            "    BB                BB    ",
            "    BBBBBBBBBBBBBBBBBBBB    ",
        }
    };
    CLIEngine::Sprite spriteI{
        {
            "                            ",
            "                            ",
            "                            ",
            "                            ",
            "<-                        ->",
            " L                        C ",
            "                            ",
            "                            ",
            "                            ",
            "                            "
        },
        {
            "                            ",
            "                            ",
            "                            ",
            "                            ",
            "BB                        RR",
            " B                        R ",
            "                            ",
            "                            ",
            "                            ",
            "                            "
        },
        {
            "                            ",
            "    GGGGGGGGGGGGGGGGGGGG    ",
            "    GGG              GGG    ",
            "    GGGGGGGG    GGGGGGGG    ",
            "    GGGGGGGG    GGGGGGGG    ",
            "    GGGGGGGG    GGGGGGGG    ",
            "    GGGGGGGG    GGGGGGGG    ",
            "    GGGGGGGG    GGGGGGGG    ",
            "    GGG              GGG    ",
            "    GGGGGGGGGGGGGGGGGGGG    ",
        }
    };

    auto C = std::make_shared<Screen_Char>("Screen_C", spriteC, 'R');
    auto L = std::make_shared<Screen_Char>("Screen_L", spriteL, 'B');
    auto I = std::make_shared<Screen_Char>("Screen_I", spriteI, 'G');

    C->init(I, L);
    L->init(C, I);
    I->init(L, C);

    ScreenPtr current = C;
    CLIEngine::ScreenTransition msg = { current, current, {} };
    while (true) {
        msg = current->loop(msg);
        current = msg.to;
    }
    return 0;
}