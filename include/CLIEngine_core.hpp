#pragma once

#include <conio.h>
#include <Windows.h>
#undef max
#undef min

#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <filesystem>
#include <fstream>
#include <optional>
#include <random>
#include <string>
#include <sstream>
#include <variant>
#include <vector>
#include <unordered_map>
#include <utility>

const char endl = '\n';

//alias
using intP = unsigned int;

namespace CLIEngine {

const int WINDOW_WIDTH = 79;
const int WINDOW_HEIGHT = 42;
const int FPS = 60;

//core components and related functions.
struct Coordinate
{
	unsigned int x;
	unsigned int y;

	Coordinate(unsigned int x = 0, unsigned int y = 0);
	~Coordinate();

	COORD to_COORD();
	bool operator==(const Coordinate& other) const;
	bool operator!=(const Coordinate& other) const;
	Coordinate operator+(const Coordinate& other) const;
};
void moveCursor(Coordinate location = { 0, 0 });
Coordinate getCursorLocation();

enum class Key
{
	UP,     // 'w' / 'W' / up arrow
	LEFT,   // 'a' / 'A' / left arrow
	DOWN,   // 's' / 'S' / down arrow
	RIGHT,  // 'd' / 'D' / right arrow

	SELECT, // space bar / enter
	PAUSE,  // 'p' / 'P' / esc

	NONE    // no input
};
Key getKey();

enum class Color
{
	BLACK,       // 'X' (fill all)
	BLUE,        // 'B'
	GREEN,       // 'G'
	CYAN,        // 'C'
	RED,         // 'R'
	PURPLE,      // 'P'
	BROWN,       // 'O' (oak)
	LIGHTGRAY,   // 'a' (ash)
	DARKGRAY,    // 'A'
	LIGHTBLUE,   // 'b'
	LIGHTGREEN,  // 'g'
	LIGHTCYAN,   // 'c'
	LIGHTRED,    // 'r'
	LIGHTPURPLE, // 'p'
	YELLOW,      // 'Y'
	WHITE,       // 'W'

	DEFAULT      // ' ' (WHITE in foreground, BLACK in background)
};

void setPalette(Color foreground = Color::WHITE, Color background = Color::BLACK);

class Sprite
{
private:
	std::vector<std::string> text;
	std::vector<std::string> font;
	std::vector<std::string> back;

private:
	static Color char2Color(char c);

public:
	Sprite(const std::vector<std::string>&, const std::vector<std::string>&, const std::vector<std::string>&);
	void draw(const Coordinate& offset = { 0, 0 });
};

enum class Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

} // end of CLIEngine namespace