#include "CLIEngine_core.hpp"

int main()
{
    CLIEngine::Sprite smile_face(
        {
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
        },
        {
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
            "                                        ",
        },
        {
            "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
            "WWWWWWWWWWWWWWXXXXXXXXXXXWWWWWWWWWWWWWWW",
            "WWWWWWWWWWXXXXXXYYYYYYYXXXXXXWWWWWWWWWWW",
            "WWWWWWWWXXXXXYYYYYYYYYYYYYYXXXXXWWWWWWWW",
            "WWWWWWXXXXYYYYYYYYYYYYYYYYYYYYXXXXWWWWWW",
            "WWWWWXXXYYYYYYYYYYYYYYYYYYYYYYYYXXXWWWWW",
            "WWWWXXXYYYYYYYYXXYYYYYYXXYYYYYYYYYXXWWWW",
            "WWWXXYYYYYYYYYXXXXYYYYXXXXXYYYYYYYYXXWWW",
            "WWWXXYYYYYYYYXXYXXYYYYXXYXXYYYYYYYYXXWWW",
            "WWXXYYYYYYYYYYXXXXYYYYXXXXYYYYYYYYYYXXWW",
            "WWXXYYYYXXYYYYYYYYYYYYYYYYYYYYXXYYYYXXWW",
            "WWXXYYYYXXXYYYYYYYYYYYYYYYYYYXXXYYYYXXWW",
            "WWWXXYYYYXXXXYYYYYYYYYYYYYYXXXXYYYYXXWWW",
            "WWWXXXYYYYYXXXXXXYYYYYYXXXXXXYYYYYXXXWWW",
            "WWWWXXXYYYYYYXXXXXXXXXXXXXXYYYYYYXXXWWWW",
            "WWWWWXXXYYYYYYYYYYYYYYYYYYYYYYYYXXXWWWWW",
            "WWWWWWWXXXXYYYYYYYYYYYYYYYYYYXXXXWWWWWWW",
            "WWWWWWWWWXXXXXXYYYYYYYYYYXXXXXXWWWWWWWWW",
            "WWWWWWWWWWWWXXXXXXXXXXXXXXXXWWWWWWWWWWWW",
            "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
        }
    );
    while (true) {
        smile_face.draw();
        Sleep(1000); // update every 1000ms = 1s
    }

    return 0;
}