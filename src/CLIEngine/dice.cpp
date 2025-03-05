#include "CLIEngine/dice.hpp"

namespace CLIEngine {

std::default_random_engine Dice::engine = std::default_random_engine{std::random_device{}()};
std::uniform_real_distribution<double> Dice::distribution = std::uniform_real_distribution<double>{0.0, 1.0};

Dice::Dice(
    const std::vector<std::string>& names, 
    const std::vector<CLIEngine::Sprite>& sprites,
    const std::vector<double>& probabilities
)
{
    if (
        names.size() != sprites.size() ||
        names.size() != probabilities.size()
    ) {
        throw std::runtime_error("Dice initialization failed; size mismatch between names/sprites/probabilities");
    }

    this->names = names;
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

void Dice::roll()
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

std::string Dice::get_result()
{
    return this->names[this->current];
}

void Dice::draw(const Coordinate& offset)
{
    this->sprites[this->current].draw(offset);
}

}