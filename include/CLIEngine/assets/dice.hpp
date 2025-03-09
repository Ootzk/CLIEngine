#include "CLIEngine/core.hpp"

namespace CLIEngine {

namespace Assets {

const std::map<intP, CLIEngine::TextLayer> standard_dice_eyes_7x3{
    {1, CLIEngine::TextLayer{{
        "       ",
        "   *   ",
        "       "
    }, '*', ' '}},
    {2, CLIEngine::TextLayer{{
        "       ",
        " *   * ",
        "       "
    }, '*', ' '}},
    {3, CLIEngine::TextLayer{{
        "   *   ",
        "   *   ",
        "   *   "
    }, '*', ' '}},
    {4, CLIEngine::TextLayer{{
        " *   * ",
        "       ",
        " *   * "
    }, '*', ' '}},
    {5, CLIEngine::TextLayer{{
        " *   * ",
        "   *   ",
        " *   * "
    }, '*', ' '}},
    {6, CLIEngine::TextLayer{{
        " *   * ",
        " *   * ",
        " *   * "
    }, '*', ' '}}
};

}

}