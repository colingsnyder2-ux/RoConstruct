// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection {
class FunctionDescriptor { public: enum Security { AnyCaller, NeedTrustedCaller = 4 }; };
template<class Class, typename Signature, int ArgCount>
class BoundFuncDesc : public FunctionDescriptor {
    char data[0x40];
public:
    template<typename Function>
    BoundFuncDesc(Function function, const char* name, const char* arg1, Security security);
    ~BoundFuncDesc();
};
}
class Base1 { public: virtual ~Base1(); };
class Base2 { public: virtual ~Base2(); };
class Instance : public Base1, public Base2 {
public:
    bool isA(std::string className) const;
};
}
using namespace RBX;
static Reflection::BoundFuncDesc<Instance, bool(std::string), 1> func_isA(&Instance::isA, "IsA", "className", Reflection::FunctionDescriptor::AnyCaller);
