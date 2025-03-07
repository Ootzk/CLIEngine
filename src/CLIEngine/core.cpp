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
	consoleCOORD.X = x; consoleCOORD.Y = y;
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

Color intP2Color(intP i)
{
	switch(i)
	{
	case 0: return Color::BLACK;
	case 1: return Color::BLUE;
	case 2: return Color::GREEN;
	case 3: return Color::CYAN;
	case 4: return Color::RED;
	case 5: return Color::PURPLE;
	case 6: return Color::BROWN;
	case 7: return Color::LIGHTGRAY;
	case 8: return Color::DARKGRAY;
	case 9: return Color::LIGHTBLUE;
	case 10: return Color::LIGHTGREEN;
	case 11: return Color::LIGHTCYAN;
	case 12: return Color::LIGHTRED;
	case 13: return Color::LIGHTPURPLE;
	case 14: return Color::YELLOW;
	case 15: return Color::WHITE;
	default: return Color::DEFAULT;
	}
}

std::string Color2str(Color color)
{
    switch(color)
    {
    case CLIEngine::Color::BLACK: return "black";
    case CLIEngine::Color::BLUE: return "blue";
    case CLIEngine::Color::GREEN: return "green";
    case CLIEngine::Color::CYAN: return "cyan";
    case CLIEngine::Color::RED: return "red";
    case CLIEngine::Color::PURPLE: return "purple";
    case CLIEngine::Color::BROWN: return "brown";
    case CLIEngine::Color::LIGHTGRAY: return "lightgray";
    case CLIEngine::Color::DARKGRAY: return "darkgray";
    case CLIEngine::Color::LIGHTBLUE: return "lightblue";
    case CLIEngine::Color::LIGHTGREEN: return "lightgreen";
    case CLIEngine::Color::LIGHTCYAN: return "lightcyan";
    case CLIEngine::Color::LIGHTRED: return "lightred";
    case CLIEngine::Color::LIGHTPURPLE: return "lightpurple";
    case CLIEngine::Color::YELLOW: return "yellow";
    case CLIEngine::Color::WHITE: return "white";
    default: return "?";
    }
}

void setPalette(Color foreground, Color background)
{
	if (foreground == Color::DEFAULT) foreground = Color::WHITE;
	if (background == Color::DEFAULT) background = Color::BLACK;
	int colorCode = static_cast<int>(foreground) + static_cast<int>(background) * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

std::pair<Color, Color> getPalette(Coordinate coordinate)
{
	WORD colorCode; DWORD numRead = 0;
	ReadConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &colorCode, 1, coordinate.to_COORD(), &numRead);
	Color background = intP2Color(static_cast<intP>(colorCode) / 16);
	Color foreground = intP2Color(static_cast<intP>(colorCode) % 16);
	return std::pair<Color, Color>{foreground, background};
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

void Sprite::draw(const Coordinate& offset) const
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