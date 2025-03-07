#pragma once
#include "core.hpp"

// TODO: make global random engine (maybe Singleton?)
// TODO: add Sprite (Animation?) for rolling

namespace CLIEngine {

template<typename T>
class Dice
{
private:
    inline static std::default_random_engine engine{std::random_device{}()};
    inline static std::uniform_real_distribution<double> distribution{0.0, 1.0};

    std::vector<T> eyes;
    std::vector<CLIEngine::Sprite> sprites;
    std::vector<double> probabilities; // cumulative;

    intP current;

public:
    Dice(
        const std::vector<T>& eyes,
        const std::vector<CLIEngine::Sprite>& sprites,
        const std::vector<double>& probabilities
    )
    {
        if (
            eyes.size() != sprites.size() ||
            eyes.size() != probabilities.size()
        ) {
            throw std::runtime_error("Dice initialization failed; size mismatch between names/sprites/probabilities");
        }
    
        this->eyes = eyes;
        this->sprites = sprites;
        this->probabilities = probabilities;
    
        double sum = std::accumulate(
            this->probabilities.begin(),
            this->probabilities.end(),
            0.0
        );
        if (sum <= 0) {
            throw std::runtime_error("Dice sum of probabilities must be positive");
        }
        for (auto& p : this->probabilities) { p /= sum; } // normalize
        std::partial_sum(
            this->probabilities.begin(),
            this->probabilities.end(),
            this->probabilities.begin()
        );
    
        this->roll(); // initialize i
    }

    void roll()
    {
        double r = this->distribution(this->engine);
        for (intP i = 0; i < this->probabilities.size(); ++i) {
            if (r <= this->probabilities[i]) {
                this->current = i;
                return;
            }
        }
        this->current = this->probabilities.size();
    }
    
    T get_result()
    {
        return this->eyes[this->current];
    }
    
    void draw(
        const CLIEngine::Coordinate& offset = { 0, 0 },
        std::optional<T> eye = std::nullopt
    )
    {
        if (eye.has_value()) {
            intP eye_index = std::find(
                this->eyes.begin(),
                this->eyes.end(),
                eye.value()
            ) - this->eyes.begin();
            this->sprites[eye_index].draw(offset);
        }
        else {
            this->sprites[this->current].draw(offset);
        }
    }
};

}