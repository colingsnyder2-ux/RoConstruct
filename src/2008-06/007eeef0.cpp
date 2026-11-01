// from server: 100% by tester
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
}

class DHTMLWindowBase { public: virtual ~DHTMLWindowBase(); };

class DHTMLWindow : public RBX::Instance, public DHTMLWindowBase
{
public:
    void unbind();
};

static RBX::Reflection::BoundFuncDesc<DHTMLWindow, void(), 0> func_Unbind(&DHTMLWindow::unbind, "Unbind", RBX::Reflection::FunctionDescriptor::AnyCaller);
