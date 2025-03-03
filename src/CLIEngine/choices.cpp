#include "CLIEngine/choices.hpp"

namespace CLIEngine {

Choices::Choices(
    CLIEngine::Key key_next,
    CLIEngine::Key key_prev,
    CLIEngine::Key key_select
) : key_next(key_next), key_prev(key_prev), key_select(key_select)
{
}

void Choices::add(
    std::shared_ptr<CLIEngine::Screen> screen,
    CLIEngine::Coordinate location,
    CLIEngine::Sprite chosen_sprite,
    CLIEngine::Sprite not_chosen_sprite
)
{
    list.push_back({screen, location, chosen_sprite, not_chosen_sprite});
    reset_cursor();
}

void Choices::reset_cursor()
{
    current = list.cbegin();
    previous = list.cend();
}

std::optional<std::shared_ptr<CLIEngine::Screen>> Choices::input(CLIEngine::Key key)
{
    if (key == key_select) {
        return std::get<0>(*current);
    }
    else if (key == key_prev) {
        previous = current;
        if (current == list.cbegin()) current = list.cend();
        --current;
        return std::nullopt;
    }
    else if (key == key_next) {
        previous = current;
        ++current;
        if (current == list.cend()) current = list.cbegin();
        return std::nullopt;
    }
    else {
        return std::nullopt;
    }
}

void Choices::draw()
{
    if (previous != current) {
        if (previous != list.cend()) {
            auto previous_offset = std::get<1>(*previous);
            auto previous_sprite = std::get<3>(*previous); // rollback sprite

            previous_sprite.draw(previous_offset);
        }
        
        auto current_offset = std::get<1>(*current);
        auto current_sprite = std::get<2>(*current); // apply chosen sprite
        
        current_sprite.draw(current_offset);

        previous = current;
    }
}

} // end of CLIEngine namespace