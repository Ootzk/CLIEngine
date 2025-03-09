#include "CLIEngine/core.hpp"

namespace CLIEngine {

class ASCIITitleGenerator
{
private:
    const std::map<char, CLIEngine::TextLayer>& charset;
    std::vector<CLIEngine::Coordinate> newline_offsets;
    std::vector< // outer vector means newline.
        std::vector< // inner vector means 'ASCII word' with same effects
            CLIEngine::Sprite
        >
    > memory;

private:
    intP getLastLineHeight() const;

public:
    ASCIITitleGenerator(
        const std::map<char, CLIEngine::TextLayer>& charset
    );
    void addWord(
        const std::string& word,
        const std::unordered_map<char, char>& text_mapping,
        const std::unordered_map<char, CLIEngine::Color>& font_mapping,
        const std::unordered_map<char, CLIEngine::Color>& back_mapping,
        CLIEngine::Color default_font = CLIEngine::Color::TRANS,
        CLIEngine::Color default_back = CLIEngine::Color::TRANS,
        intP space = 1
    );
    void newLine(int x_offset, int y_offset);
    void newLine();
    void draw(const CLIEngine::Coordinate& offset = {0, 0});
};

}