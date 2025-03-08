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
        T item,
        CLIEngine::Coordinate location,
        CLIEngine::Sprite chosen_sprite,
        CLIEngine::Sprite not_chosen_sprite
    )
    {
        list.push_back({item, location, chosen_sprite, not_chosen_sprite});
        reset();
    }
    
    void reset()
    {
        current = list.cbegin();
        previous = list.cend();
    }

    Choices<T>& operator++() {
        ++current;
        if (current == list.cend()) {
            current = list.cbegin();
        }
        return *this;
    }

    Choices<T>& operator--() {
        if (current == list.cbegin()) {
            current = list.cend();
        }
        --current;
        return *this;
    }

    intP size() const {
        return list.size();
    }

    intP index() const
    {
        return current - list.cbegin();
    }

    T get() const
    {
        return std::get<0>(*current);
    }

    std::optional<T> input(CLIEngine::Key key)
    {
        if (key == key_select) {
            return std::get<0>(*current);
        }
        else if (key == key_prev) {
            previous = current;
            --(*this);
            return std::nullopt;
        }
        else if (key == key_next) {
            previous = current;
            ++(*this);
            return std::nullopt;
        }
        else {
            return std::nullopt;
        }
    }
    
    void draw()
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
};

} // end of CLIEngine namespace