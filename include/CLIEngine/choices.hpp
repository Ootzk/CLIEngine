#pragma once
#include "core.hpp"

namespace CLIEngine {

class Choices
{
using List = std::vector<
    std::tuple<
        std::shared_ptr<CLIEngine::Screen>,
        CLIEngine::Coordinate,
        CLIEngine::Sprite, // chosen
        CLIEngine::Sprite  // not chosen
    >
>;
using Cursor = List::const_iterator;

private:
    List list;
    Cursor current = list.cbegin();
    Cursor previous = list.cend();

    CLIEngine::Key key_next;
    CLIEngine::Key key_prev;
    CLIEngine::Key key_select;

public:
    Choices(
        CLIEngine::Key = CLIEngine::Key::DOWN,
        CLIEngine::Key = CLIEngine::Key::UP,
        CLIEngine::Key = CLIEngine::Key::SELECT
    );
    
    void add(
        std::shared_ptr<CLIEngine::Screen>,
        CLIEngine::Coordinate,
        CLIEngine::Sprite,
        CLIEngine::Sprite
    );
    void reset_cursor();

    std::optional<std::shared_ptr<CLIEngine::Screen>> input(CLIEngine::Key);
    void draw(); // TODO: 
};

} // end of CLIEngine namespace