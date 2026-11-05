// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_12fb1623c20ba0ae.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace RBX {
struct BrickColor { int number; BrickColor(int n) : number(n) {} };
class Player;
class Instance {
public:
    virtual ~Instance();
    char padding[0x100];
    Instance* parent;
    Player* getPlayer();
};
class Flag : public Instance {
public:
    char more[0x178 - 0x108];
    BrickColor teamColor;
    bool inactive;
};
class Player {
public:
    BrickColor getTeamColor() const;
};
class Teams {
public:
    Teams* findTeam(Player*);
    void captured(Player*);
};
struct Source { char data[4]; };
struct FlagSignal {
    void operator()(Source* source, boost::shared_ptr<Instance> flag);
};
extern FlagSignal flagCaptured;
int __cdecl isPart(Instance*);
Flag* __cdecl findFlag(Instance*);
boost::shared_ptr<Flag> __cdecl sharedFrom(Flag*);
Teams* __cdecl findTeams(void*);
class FlagStand {
public:
    char padding[0x14];
    Source source;
    char more[0x3fc - 0x18];
    BrickColor teamColor;
    void onTouched(boost::shared_ptr<Instance> other);
};
void FlagStand::onTouched(boost::shared_ptr<Instance> other)
{
    Instance* part = other->parent;
    if (!isPart(part))
        return;
    Player* player = part->getPlayer();
    if (!player)
        return;
    Flag* flag = findFlag(part);
    if (!flag || flag->inactive)
        return;
    int myColor = teamColor.number;
    if (flag->teamColor.number != myColor)
        return;
    if (player->getTeamColor().number == myColor)
        return;
    Source* src = &source;
    flagCaptured(src, sharedFrom(flag));
    Teams* all = findTeams(this);
    if (Teams* teams = all->findTeam(player))
        teams->captured(player);
}
}
