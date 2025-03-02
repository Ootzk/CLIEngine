#include "CLIEngine_core.hpp"

int main()
{
    CLIEngine::Sprite logo(
        {
            "_____ _      _____ ______             _             ",
            "/ ____| |    |_   _|  ____|           (_)           ",
            "| |   | |      | | | |__   _ __   __ _ _ _ __   ___ ",
            "| |   | |      | | |  __| | '_ \\ / _` | | '_ \\ / _ \\",
            "| |___| |____ _| |_| |____| | | | (_| | | | | |  __/",
            "\\_____|______|_____|______|_| |_|\\__, |_|_| |_|\\___|",
            "                                  __/ |             ",
            "                                 |___/              "
        },
        {
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "RRRRRRBBBBBBBGGGGGGXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
        },
        {
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        }
    );

    while (true) {
        logo.draw();
        Sleep(1000); // update every 1000ms = 1s
    }
}