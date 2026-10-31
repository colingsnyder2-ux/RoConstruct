// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };
namespace Network { class Peer : public Instance, public Service { public: int getRakStatsString(int verbosityLevel); }; }
namespace Reflection {
template<class Class, typename Signature, int ArgCount>
class BoundFuncDesc {
    char data[0x40];
public:
    template<typename Function>
    BoundFuncDesc(Function function, const char* name, const char* arg1, int def, int security);
    ~BoundFuncDesc();
};
}
}
using namespace RBX;
static Reflection::BoundFuncDesc<Network::Peer, int(int), 1> func_GetRakStatsString(&Network::Peer::getRakStatsString, "GetRakStatsString", "verbosityLevel", 0, 1);
