// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_317ea390c5522f93.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
#include "v8datamodel/BrickColor.h"
typedef G3D::Color3 Vector3;
struct Team {
    int func_005d5f40() const;
};

typedef RBX::BrickColor TeamColor;

namespace RBX {
    class Instance { public:
        virtual ~Instance();
        char padding[0x100];
        Instance* next;
    };

    typedef std::vector<boost::shared_ptr<Instance> > Children;

    struct ServiceProvider : Instance {
        Children* children;
        unsigned int func_0048ae20() const;
    };

    struct VTeams : Instance {
        Vector3 func_005d6180(int teamId);
    };
}

namespace RBX { namespace Network {
    class Player : public RBX::Instance { public:
        char padding[0x68];
        Team* team;
        int reserved;
        TeamColor color;
        bool neutral;
        TeamColor getTeamColor() const { return color; }
    };
}

}
extern RBX::ServiceProvider* __cdecl func_00491d50(RBX::Instance*);
extern const Vector3& __cdecl func_00514a60();
Vector3 RBX::VTeams::func_005d6180(int teamId)
{
    ServiceProvider* provider = func_00491d50(this);
    for (unsigned int i = 0; i < provider->func_0048ae20(); ++i) {
        Children* children = provider->children;
        Network::Player* player = dynamic_cast<Network::Player*>((*children)[i].get());

        if (player && !player->neutral && player->team &&
            player->team->func_005d5f40() == teamId) {
            return player->getTeamColor().color3();
        }
    }
    return func_00514a60();
}
