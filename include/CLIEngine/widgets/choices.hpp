#pragma once
#include "CLIEngine/core.hpp"

namespace CLIEngine {

template<typename T>
class Choices
{
using List = std::vector<
    std::tuple<
        T,
        CLIEngine::Coordinate,
        CLIEngine::Sprite, // chosen
        CLIEngine::Sprite  // not chosen
    >
>;
using Cursor = typename List::const_iterator;

private:
    List list;
    Cursor current = list.cbegin();
    Cursor previous = list.cend();

    CLIEngine::Key key_next;
    CLIEngine::Key key_prev;
    CLIEngine::Key key_select;

public:
    Choices(
        CLIEngine::Key key_next = CLIEngine::Key::DOWN,
        CLIEngine::Key key_prev = CLIEngine::Key::UP,
        CLIEngine::Key key_select = CLIEngine::Key::SELECT
    ) : key_next(key_next), key_prev(key_prev), key_select(key_select)
    {
    }
    
    void add(
        std::shared_ptr<CLIEngine::Screen> screen,
        CLIEngine::Coordinate location,
        CLIEngine::Sprite chosen_sprite,
        CLIEngine::Sprite not_chosen_sprite
    )
    {
        list.push_back({screen, location, chosen_sprite, not_chosen_sprite});
        reset_cursor();
    }
    
    void reset_cursor()
    {
        current = list.cbegin();
        previous = list.cend();
    }

    std::optional<T> input(CLIEngine::Key key)
    {
        if (key == key_select) {
            return std::get<0>(*this->current);
        }
        else if (key == key_prev) {
            this->previous = this->current;
            if (this->current == this->list.cbegin()) {
                this->current = this->list.cend();
            }
            --this->current;
            return std::nullopt;
        }
        else if (key == key_next) {
            this->previous = current;
            ++this->current;
            if (this->current == this->list.cend()) {
                this->current = list.cbegin();
            }
            return std::nullopt;
        }
        else {
            return std::nullopt;
        }
    }
    
    void draw()
    {
        if (this->previous != this->current) {
            if (this->previous != this->list.cend()) {
                auto previous_offset = std::get<1>(*this->previous);
                auto previous_sprite = std::get<3>(*this->previous); // rollback sprite
    
                previous_sprite.draw(previous_offset);
            }
            
            auto current_offset = std::get<1>(*this->current);
            auto current_sprite = std::get<2>(*this->current); // apply chosen sprite
            
            current_sprite.draw(current_offset);
    
            this->previous = this->current;
        }
    }
};

} // end of CLIEngine namespace