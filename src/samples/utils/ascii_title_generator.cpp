#include "CLIEngine/assets/charset.hpp"
#include "CLIEngine/utils.hpp"

int main()
{
    CLIEngine::ASCIITitleGenerator ascii(
        CLIEngine::Assets::alphabets_font1
    );

    char mainframe = '#';
    char background = ' ';

    ascii.addWord(
        "1",
        {{mainframe, ' '}}, // skeleton char will disappeared in text layer
        {{}},
        {
            {mainframe, CLIEngine::Color::WHITE}, // but, skeleton will filled white in background layer
            {background, CLIEngine::Color::LIGHTBLUE} // also background will filled lightblue in background layer
        } 
    );
    ascii.addWord(" ", {{}}, {{}}, {{}});

    ascii.addWord(
        "THE QUICK",
        {{}},
        {{mainframe, CLIEngine::Color::GREEN}}, // skeleton is green charactors
        {{mainframe, CLIEngine::Color::WHITE}},
        CLIEngine::Color::TRANS,
        CLIEngine::Color::TRANS,
        3 // wide-space between charactor
    );
    
    ascii.newLine(); // if offset not given, it will automatically set next line location.

    ascii.addWord(
        "2",
        {{mainframe, '2'}}, // skeleton of ascii is consist of (many) 2s!
        {{mainframe, CLIEngine::Color::RED}}, // and their color is red!
        {{}}
    );
    ascii.addWord(" ", {{}}, {{}}, {{}});
    ascii.addWord(
        "BROWN FOX",
        {{mainframe, ' '}},
        {{}},
        {{mainframe, CLIEngine::Color::BROWN}}
    );

    ascii.newLine(10, 2); // if offset given, new line will start with given offset from last new line 

    ascii.addWord(
        "3",
        {{}},
        {
            {mainframe, CLIEngine::Color::PURPLE},
            {background, CLIEngine::Color::LIGHTGRAY}
        },
        {{background, CLIEngine::Color::RED}}
    );
    ascii.addWord(" ", {{}}, {{}}, {{}});
    ascii.addWord(
        "JUMPS OVER",
        {{mainframe, 'E'}},
        {{}},
        {{}}
    );

    ascii.newLine(-10, 2); // rollback x starting point

    ascii.addWord(
        "4",
        {{mainframe, '$'}},
        {{mainframe, CLIEngine::Color::GREEN}},
        {{mainframe, CLIEngine::Color::LIGHTGREEN}} // 4 dollar.
    );
    ascii.addWord(" ", {{}}, {{}}, {{}});
    ascii.addWord(
        "THE LAZY DOG",
        {{mainframe, ' '}},
        {{}},
        {{background, CLIEngine::Color::YELLOW}}
    );

    intP x = 0, y = 0;
    while (true) {
        system("cls");
        ascii.draw({x, y});
        Sleep(1000);
        x += 1, y += 1;
        if (x == 10) x = 0;
        if (y == 10) y = 0;
    }
    return 0;
}