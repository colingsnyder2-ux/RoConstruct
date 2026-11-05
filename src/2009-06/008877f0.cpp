// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 007f1980  unit: seg_007f0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007f1980
//

#include <string>

namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { AnyCaller, NeedTrustedCaller = 4 };
};

template<class Class, typename Signature, int ArgCount>
class BoundFuncDesc : public FunctionDescriptor
{
    char data[0x40];
public:
    template<typename Function>
    BoundFuncDesc(Function function, const char* name, const char* arg1, Security security);
    ~BoundFuncDesc();
};
}

class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };

namespace Network {
class Players : public Instance, public Service
{
public:
    void m_008877f0(std::string url);
};
}
}

using namespace RBX;

static Reflection::BoundFuncDesc<Network::Players, void(std::string), 1> func_m_008877f0(&Network::Players::m_008877f0, "SetChatFilterUrl", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
