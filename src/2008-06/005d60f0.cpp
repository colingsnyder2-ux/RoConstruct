// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_bf87d4f75e01e735.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/BrickColor.h"
#include <vector>
#include <boost/shared_ptr.hpp>
namespace RBX {
    class Instance { public:
        virtual ~Instance();
        char pad[0x100];
        Instance* next;
    };

    typedef std::vector<boost::shared_ptr<Instance> > Children;

    struct ServiceProvider : Instance {
        Children* children;
        unsigned int size();
    };

    namespace Network {
        class Player : public Instance { public:
            char pad[0x70];
            BrickColor value;
            bool flag;
            BrickColor getTeamColor() const { return value; }
            bool getNeutral() const { return flag; }
        };
    }

    struct VTeams : Instance {
        int count(BrickColor value);
    };
}

RBX::ServiceProvider* __cdecl func_00491d50(RBX::Instance*);
int RBX::VTeams::count(BrickColor value)
{
    int result = 0;
    ServiceProvider* provider = func_00491d50(this);
    for (unsigned int i = 0; i < provider->size(); ++i) {
        Children* children = provider->children;
        Network::Player* player = dynamic_cast<Network::Player*>((*children)[i].get());

        if (player && !player->getNeutral() && player->getTeamColor() == value)
            ++result;
    }
    return result;
}
