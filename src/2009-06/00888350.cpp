// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { AnyCaller, RobloxPlaceSecurity, NeedTrustedCaller = 4 };
};

template<class Class, typename Signature, int ArgCount>
class BoundFuncDesc : public FunctionDescriptor
{
    char data[0x40];
public:
    template<typename Function, typename A1, typename A2>
    BoundFuncDesc(Function function, const char* name, const char* arg1, A1 def1, const char* arg2, A2 def2, Security security);
    ~BoundFuncDesc();
};
}

class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };

class NetworkSettings : public Instance, public Service
{
public:
    void applyNetworkSimulator(int minExtraPing, int extraPingVariance);
};
}

using namespace RBX;

static Reflection::BoundFuncDesc<NetworkSettings, void(int, int), 2> func_ApplyNetworkSimulator(&NetworkSettings::applyNetworkSimulator, "ApplyNetworkSimulator", "minExtraPing", 0, "extraPingVariance", 0, Reflection::FunctionDescriptor::RobloxPlaceSecurity);
