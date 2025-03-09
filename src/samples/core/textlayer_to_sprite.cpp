#include "CLIEngine/core.hpp"

CLIEngine::TextLayer elephant_textlayer{
    {
        "                  .,;>>%%%%%>>;,.                                           ",
        "           .>%%%%%%%%%%%%%%%%%%%%>,.                                        ",
        "         .>%%%%%%%%%%%%%%%%%%>>,%%%%%%;,.                                   ",
        "       .>>>>%%%%%%%%%%%%%>>,%%%%%%%%%%%%,>>%%,.                             ",
        "     .>>%>>>>%%%%%%%%%>>,%%%%%%%%%%%%%%%%%,>>%%%%%,.                        ",
        "   .>>%%%%%>>%%%%>>,%%>>%%%%%%%%%%%%%%%%%%%%,>>%%%%%%%,                     ",
        "  .>>%%%%%%%%%%>>,%%%%%%>>%%%%%%%%%%%%%%%%%%,>>%%%%%%%%%%.                  ",
        " .>>%%%%%%%%%%>>,>>>>%%%%%%%%%%'..`%%%%%%%%,;>>%%%%%%%%%>%%.                ",
        ".>>%%%>>>%%%%%>,%%%%%%%%%%%%%%.%%%,`%%%%%%,;>>%%%%%%%%>>>%%%%.              ",
        ">>%%>%>>>%>%%%>,%%%%%>>%%%%%%%%%%%%%`%%%%%%,>%%%%%%%>>>>%%%%%%%.            ",
        ">>%>>>%%>>>%%%%>,%>>>%%%%%%%%%%%%%%%%`%%%%%%%%%%%%%%%%%%%%%%%%%%.           ",
        ">>%%%%%%%%%%%%%%,>%%%%%%%%%%%%%%%%%%%'%%%,>>%%%%%%%%%%%%%%%%%%%%%.          ",
        ">>%%%%%%%%%%%%%%%,>%%%>>>%%%%%%%%%%%%%%%,>>%%%%%%%%>>>>%%%%%%%%%%%.         ",
        ">>%%%%%%%%;%;%;%%;,%>>>>%%%%%%%%%%%%%%%,>>>%%%%%%>>;';>>%%%%%%%%%%%%.       ",
        "`>%%%%%%%%%;%;;;%;%,>%%%%%%%%%>>%%%%%%%%,>>>%%%%%%%%%%%%%%%%%%%%%%%%%%.     ",
        " >>%%%%%%%%%,;;;;;%%>,%%%%%%%%>>>>%%%%%%%%,>>%%%%%%%%%%%%%%%%%%%%%%%%%%%.   ",
        " `>>%%%%%%%%%,%;;;;%%%>,%%%%%%%%>>>>%%%%%%%%,>%%%%%%'%%%%%%%%%%%%%%%%%%%>>. ",
        "  `>>%%%%%%%%%%>,;;%%%%%>>,%%%%%%%%>>%%%%%%';;;>%%%%%,`%%%%%%%%%%%%%%%>>%%>.",
        "   >>>%%%%%%%%%%>> %%%%%%%%>>,%%%%>>>%%%%%';;;;;;>>,%%%,`%     `;>%%%%%%>>%%",
        "   `>>%%%%%%%%%%>> %%%%%%%%%>>>>>>>>;;;;'.;;;;;>>%%'  `%%'          ;>%%%%%>",
        "    >>%%%%%%%%%>>; %%%%%%%%>>;;;;;;''    ;;;;;>>%%%                   ;>%%%%",
        "    `>>%%%%%%%>>>, %%%%%%%%%>>;;'        ;;;;>>%%%'                    ;>%%%",
        "     >>%%%%%%>>>':.%%%%%%%%%%>>;        .;;;>>%%%%                    ;>%%%'",
        "     `>>%%%%%>>> ::`%%%%%%%%%%>>;.      ;;;>>%%%%'                   ;>%%%' ",
        "      `>>%%%%>>> `:::`%%%%%%%%%%>;.     ;;>>%%%%%                   ;>%%'   ",
        "       `>>%%%%>>, `::::`%%%%%%%%%%>,   .;>>%%%%%'                   ;>%'    ",
        "        `>>%%%%>>, `:::::`%%%%%%%%%>>. ;;>%%%%%%                    ;>%,    ",
        "         `>>%%%%>>, :::::::`>>>%%%%>>> ;;>%%%%%'                     ;>%,   ",
        "          `>>%%%%>>,::::::,>>>>>>>>>>' ;;>%%%%%                       ;%%,  ",
        "            >>%%%%>>,:::,%%>>>>>>>>'   ;>%%%%%.                        ;%%  ",
        "             >>%%%%>>``%%%%%>>>>>'     `>%%%%%%.                            ",
        "             >>%%%%>> `@@a%%%%%%'     .%%%%%%%%%.                           ",
        "             `a@@a%@'    `%a@@'       `a@@a%a@@a'                           "
    },
    '%',
    ' '
};

int main()
{
    auto elephant = elephant_textlayer.makeSprite(
        {},
        {
            {elephant_textlayer.mainframe(), CLIEngine::Color::BLACK},
            {'>', CLIEngine::Color::LIGHTGRAY},
            {';', CLIEngine::Color::DARKGRAY}
        },
        {
            {elephant_textlayer.mainframe(), CLIEngine::Color::DARKGRAY},
            {elephant_textlayer.background(), CLIEngine::Color::YELLOW},
            {'>', CLIEngine::Color::DARKGRAY},
            {';', CLIEngine::Color::BLACK},
        }
    );
    https://namu.wiki/w/%EC%98%A4%EB%B0%A9%EC%83%89
    elephant.addPadding(CLIEngine::Direction::RIGHT, 4, 'R', CLIEngine::Color::WHITE, CLIEngine::Color::BLUE);
    elephant.addPadding(CLIEngine::Direction::LEFT, 4, 'L', CLIEngine::Color::BLACK, CLIEngine::Color::WHITE);
    elephant.addPadding(CLIEngine::Direction::DOWN, 2, 'D', CLIEngine::Color::WHITE, CLIEngine::Color::RED);
    elephant.addPadding(CLIEngine::Direction::UP, 2, 'U', CLIEngine::Color::WHITE, CLIEngine::Color::BLACK);

    elephant.draw({0, 0});

    auto credit = CLIEngine::Sprite{
        {"https://www.asciiart.eu/animals/elephants - Baby Elephant, by Susie Oviatt"},
        {"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb                                 "},
        {"                                            AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"}
    };
    
    credit.draw({0, elephant.height() + 1});

    while(true) { Sleep(1000); }
    return 0;
}