#pragma once
#include "core.hpp"

// TODO: make global random engine (maybe Singleton?)
// TODO: add Sprite (Animation?) for rolling

namespace CLIEngine {

class Dice
{
private:
    static std::default_random_engine engine;
    static std::uniform_real_distribution<double> distribution;

    std::vector<std::string> names;
    std::vector<CLIEngine::Sprite> sprites;
    std::vector<double> probabilities; // cumulative;

    intP current;

public:
    Dice(
        const std::vector<std::string>&,
        const std::vector<CLIEngine::Sprite>&,
        const std::vector<double>&
    );

    void roll();
    std::string get_result();
    void draw(const Coordinate& offset = { 0, 0 });
};

}