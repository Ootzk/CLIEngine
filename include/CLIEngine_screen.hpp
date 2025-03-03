#include "CLIEngine_core.hpp"

namespace CLIEngine {

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

}  // end of CLIEngine namespace