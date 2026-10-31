// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

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
    BoundFuncDesc(Function function, const char* name, Security security);
    ~BoundFuncDesc();
};
}

class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };

class Owner : public Instance, public Service
{
public:
    void m_008906e0();
};
}

using namespace RBX;

static Reflection::BoundFuncDesc<Owner, void(), 0> func_m_008906e0(&Owner::m_008906e0, "GetMinutesAfterMidnight", Reflection::FunctionDescriptor::AnyCaller);
