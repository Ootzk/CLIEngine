#include "CLIEngine/core.hpp"

namespace CLIEngine {

Coordinate::Coordinate(unsigned int x, unsigned int y) :
	x(x), y(y)
{
}

Coordinate::~Coordinate()
{
}

COORD Coordinate::to_COORD()
{
	COORD consoleCOORD;
	consoleCOORD.X = 2 * x; consoleCOORD.Y = y;
	return consoleCOORD;
}
bool Coordinate::operator==(const Coordinate& other) const
{
	return (x == other.x && y == other.y);
}
bool Coordinate::operator!=(const Coordinate& other) const
{
	return !(*this == other);
}
Coordinate Coordinate::operator+(const Coordinate& other) const
{
	return Coordinate(x + other.x, y + other.y);
}
void moveCursor(Coordinate location)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), location.to_COORD());
}
Coordinate getCursorLocation()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufInfo);

	Coordinate coordinate;
	coordinate.x = bufInfo.dwCursorPosition.X / 2;
	coordinate.y = bufInfo.dwCursorPosition.Y;
	return coordinate;
}

Key getKey()
{
	if (_kbhit()) {
		int key = _getch();
		if (key == 224 || key == 0) { //special key: 2 bytes
			key = _getch();
			switch (key)
			{
			case 72: return Key::UP;
			case 80: return Key::DOWN;
			case 75: return Key::LEFT;
			case 77: return Key::RIGHT;
			}
		}
		else {
			switch (key)
			{
			case 'w': return Key::UP;
			case 'W': return Key::UP;
			case 's': return Key::DOWN;
			case 'S': return Key::DOWN;
			case 'a': return Key::LEFT;
			case 'A': return Key::LEFT;
			case 'd': return Key::RIGHT;
			case 'D': return Key::RIGHT;
			case ' ': return Key::SELECT;
			case 13:  return Key::SELECT;
			case 'p': return Key::PAUSE;
			case 'P': return Key::PAUSE;
			case 27:  return Key::PAUSE;
			}
		}
	}
	return Key::NONE;
}

void setPalette(Color foreground, Color background)
{
	if (foreground == Color::DEFAULT) foreground = Color::WHITE;
	if (background == Color::DEFAULT) background = Color::BLACK;
	int colorCode = static_cast<int>(foreground) + static_cast<int>(background) * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

Sprite::Sprite(
	const std::vector<std::string>& text,
	const std::vector<std::string>& font,
	const std::vector<std::string>& back
)
{
    const intP T = text.size();
    const intP F = font.size();
    const intP B = back.size();

    if ((T != F) || (T != B) || (F != B)) {
        throw std::runtime_error(
            "text: " + std::to_string(text.size())\
            + ", font: " + std::to_string(font.size())\
            + ", back: " + std::to_string(back.size())
        );
    }
    this->text = text;
	this->font = font;
	this->back = back;
}

Color char2Color(char c)
{
	switch (c)
	{
	case 'X': return Color::BLACK;
	case 'B': return Color::BLUE;
	case 'G': return Color::GREEN;
	case 'C': return Color::CYAN;
	case 'R': return Color::RED;
	case 'P': return Color::PURPLE;
	case 'O': return Color::BROWN;
	case 'a': return Color::LIGHTGRAY;
	case 'A': return Color::DARKGRAY;
	case 'b': return Color::LIGHTBLUE;
	case 'g': return Color::LIGHTGREEN;
	case 'c': return Color::LIGHTCYAN;
	case 'r': return Color::LIGHTRED;
	case 'p': return Color::LIGHTPURPLE;
	case 'Y': return Color::YELLOW;
	case 'W': return Color::WHITE;
	default: return Color::DEFAULT;
	}
}

void Sprite::draw(const Coordinate& offset)
{
    moveCursor(offset);
    for (intP i = 0; i < text.size(); ++i) {
        std::string T = text[i];
        std::string F = font[i];
        std::string B = back[i];

        for (intP j = 0; j < T.size(); ++j) {
            char t = T[j];
            char f = F[j];
            char b = B[j];

            setPalette(char2Color(f), char2Color(b));
            std::cout << t;
        }
        moveCursor({ offset.x, getCursorLocation().y + 1 });
    }
    setPalette();
    moveCursor(offset);
}

Screen::Screen(const std::string& name) : name(name)
{
}

void Screen::clear()
{
    system("cls");
}

void Screen::wait()
{
    Sleep(1000 / FPS);
}

ScreenTransition Screen::loop(const ScreenTransition& previous)
{
    this->enter(previous);

    std::optional<ScreenTransition> future = std::nullopt;
    while (!future.has_value()) {
        future = this->update();
    }

    this->exit(future.value());

    return future.value();
}

} // end of namespace CLIEngine