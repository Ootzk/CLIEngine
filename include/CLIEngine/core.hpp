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
#include <map>
#include <memory>
#include <numeric>
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

enum class Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

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

	TRANS        // ' ' (transparent; avoid keyword)
};
Color char2Color(char c);
char Color2char(Color color);
Color intP2Color(intP i);
std::string Color2str(Color color);

void setPalette(Color foreground = Color::WHITE, Color background = Color::BLACK);
std::pair<Color, Color> getPalette(Coordinate coordinate);

class Sprite
{
private:
	std::vector<std::string> text;
	std::vector<std::string> font;
	std::vector<std::string> back;

private:
	static void checkFormat(const std::vector<std::string>&, const std::vector<std::string>&, const std::vector<std::string>&);

public:
	Sprite(const std::vector<std::string>&, const std::vector<std::string>&, const std::vector<std::string>&);
	void draw(const Coordinate& offset = { 0, 0 }) const;
	intP width() const;
	intP height() const;
	void addPadding(Direction dir, intP count, char text = ' ', Color font = Color::TRANS, Color back = Color::TRANS);
	void changeText(char from, char to);
	void changeFontColor(Color from, Color to);
	void changeBackColor(Color from, Color to);
};

class TextLayer : public std::vector<std::string>
{
private:
	char mainframe_;
	char background_;

public:
	TextLayer(
		const std::vector<std::string>& textlayer,
		char mainframe = '#',
		char background = ' '
	);
	char mainframe() const;
	char background() const;
	Sprite makeSprite(
		const std::unordered_map<char, char>& textmapping,
		const std::unordered_map<char, Color>& fontmapping,
		const std::unordered_map<char, Color>& backmapping,
		Color fontdefault = Color::BLACK,
		Color backdefault = Color::TRANS
	) const;
};

struct ScreenTransition; // forward declaration

class Screen : public std::enable_shared_from_this<Screen>
{
protected:
    static void clear();
    static void wait();

// handle input
    virtual std::optional<std::shared_ptr<Screen>> input() = 0;

// state machine pattern
    virtual void enter(const ScreenTransition&) = 0;
    virtual void exit(const ScreenTransition&) = 0;
    
    virtual void draw() = 0;

    virtual std::optional<ScreenTransition> update() = 0;

public:
    const std::string name;
    ScreenTransition loop(const ScreenTransition&);

    Screen(const std::string&);
};

struct ScreenTransition
{
    std::shared_ptr<Screen> from;
    std::shared_ptr<Screen> to;

    std::string message;
};

} // end of CLIEngine namespace