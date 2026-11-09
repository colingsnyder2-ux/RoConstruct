// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_32a2e9a5b4018be6.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
// from server: 81% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace RBX {
struct Instance {
    virtual ~Instance();
    char pad[0xdc - 4];
};

struct ServiceProvider : Instance {
    int active;
};
}

#pragma pointers_to_members(full_generality, multiple_inheritance)
struct Player;
struct Scheduler;

int __cdecl eligible(Player*);
RBX::ServiceProvider* __cdecl func_00491d50(RBX::Instance*);
Scheduler* __cdecl getScheduler(Player*);
bool __cdecl ready(Player*, int);
struct Time {
    double sec;
    Time() : sec(0) {}
    static Time now();
    struct Interval { double sec; Interval() : sec(0) {} double seconds() const { return sec; } };
};
Time::Interval operator-(const Time& a, const Time& b);
struct IdleSignal { void operator()(double); };

extern double interval;
extern double delayValue;


boost::shared_ptr<Player> getHandle(Player*);
struct Scheduler {void delay(boost::function0<void>, double);};

struct Player : RBX::Instance {
    IdleSignal idled;
    Time timestamp;
    void update();
};

#pragma float_control(precise, off)
void Player::update()
{
    if (!eligible(this))
        return;

    if (timestamp.sec != 0.0) {
        Time::Interval elapsed = Time::now() - timestamp;
        if (elapsed.seconds() > interval) {
            RBX::ServiceProvider* provider = func_00491d50(this);
            if (provider && provider->active && ready(this, 1))
                idled(elapsed.seconds());
        }
    }

    Scheduler* scheduler = getScheduler(this);
    if (scheduler)
        scheduler->delay(boost::bind(&Player::update, getHandle(this)), delayValue);
}

