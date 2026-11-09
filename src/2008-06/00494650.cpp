// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_playeridleabid0734bec39718021.cpp

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
    char pad[0x100];
    Instance* next;
};

struct ServiceProvider : Instance {
    char pad2[0x98];
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
double __cdecl currentTime();

extern double interval;
extern double delayValue;

struct Reporter {
    void report(const void*, float);
};
extern Reporter reporter;

boost::shared_ptr<Player> getHandle(Player*);
struct Scheduler {void delay(boost::function0<void>, double);};

struct Player : RBX::Instance {
    char pad2[0xc8];
    double timestamp;
    void update();
};

#pragma float_control(precise, off)
void Player::update()
{
    if (!eligible(this))
        return;

    if (timestamp != 0.0) {
        double elapsed = currentTime() - timestamp;
        if (elapsed > interval) {
            RBX::ServiceProvider* provider = func_00491d50(this);
            if (provider && provider->active && ready(this, 1))
                reporter.report(reinterpret_cast<char*>(this) + 0x14,
                                static_cast<float>(elapsed));
        }
    }

    Scheduler* scheduler = getScheduler(this);
    if (scheduler)
        scheduler->delay(boost::bind(&Player::update, getHandle(this)), delayValue);
}
