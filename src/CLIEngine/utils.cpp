#include "CLIEngine/utils.hpp"

namespace CLIEngine {

ASCIITitleGenerator::ASCIITitleGenerator(
    const std::map<char, CLIEngine::TextLayer>& charset
)
    : charset(charset)
{
    newLine(0, 0);
}

intP ASCIITitleGenerator::getLastLineHeight() const
{
    if (memory.empty() || memory.back().empty()) return 0;

    return std::max_element(
        memory.back().begin(),
        memory.back().end(),
        [](
            const CLIEngine::Sprite& A,
            const CLIEngine::Sprite& B
        ) {
            return A.height() < B.height();
        }
    )->height();
}

void ASCIITitleGenerator::addWord(
    const std::string& word,
    const std::unordered_map<char, char>& text_mapping,
    const std::unordered_map<char, CLIEngine::Color>& font_mapping,
    const std::unordered_map<char, CLIEngine::Color>& back_mapping,
    CLIEngine::Color default_font,
    CLIEngine::Color default_back,
    intP space
)
{
    for (char charactor : word) {
        auto ascii_sprite = charset.find(charactor)->second.makeSprite(
            text_mapping,
            font_mapping,
            back_mapping,
            default_font,
            default_back
        );
        memory.back().emplace_back(ascii_sprite);

        if (space > 0 && word.size() > 1) {
            auto space_sprite = CLIEngine::TextLayer{
                std::vector<std::string>(ascii_sprite.height(), std::string(space, ' '))
            }.makeSprite(
                text_mapping,
                font_mapping,
                back_mapping,
                default_font,
                default_back
            );
            memory.back().emplace_back(space_sprite);
        }
    }
}

void ASCIITitleGenerator::newLine(int x_offset, int y_offset)
{
    if (newline_offsets.empty()) {
        newline_offsets.emplace_back(x_offset, y_offset);
    }
    else {
        CLIEngine::Coordinate prev_newline_offset = newline_offsets.back();

        int next_x = (int)prev_newline_offset.x + x_offset;
        int next_y = (int)prev_newline_offset.y + getLastLineHeight() + y_offset;
        newline_offsets.emplace_back(next_x, next_y);
    }
    
    memory.emplace_back();
}

void ASCIITitleGenerator::newLine()
{
    newLine(0, 0);
}

void ASCIITitleGenerator::draw(const CLIEngine::Coordinate &offset)
{
    CLIEngine::Coordinate current{0, 0};
    for (intP l = 0; l < memory.size(); ++l) {
        current = newline_offsets[l] + offset;
        for (auto& ascii : memory[l]) {
            ascii.draw(current);
            current.x += ascii.width();
        }
    }
}

}