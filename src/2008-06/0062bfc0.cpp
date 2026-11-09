// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <list>
namespace RBX {
class Flag;
class FlagStand {
public:
    Flag* GetFlag();
};
class FlagStandService {
public:
    virtual ~FlagStandService();
    char pad[0x130 - 4];
    std::list<FlagStand*> flagStands;
    FlagStand* FindStandWithFlag(Flag* f);
};
FlagStand* FlagStandService::FindStandWithFlag(Flag* f)
{
    if (flagStands.empty())
        return 0;
    for (std::list<FlagStand*>::const_iterator iter = flagStands.begin(); iter != flagStands.end(); iter++) {
        if ((*iter)->GetFlag() == f)
            return *iter;
    }
    return 0;
}
}
