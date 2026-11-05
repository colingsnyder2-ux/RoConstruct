// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { None = 0 };
};
template<class Class, class Signature, int N>
class BoundFuncDesc
{
    char data[0x50];
public:
    BoundFuncDesc(void (Class::*function)(float), const char* name, const char* arg1name, FunctionDescriptor::Security security);
    ~BoundFuncDesc();
};
}
class VBase { public: virtual ~VBase(); };
class Instance : public virtual VBase { public: virtual ~Instance(); };
class Pad { public: virtual ~Pad(); char pad[0x14c - 4]; };
class Humanoid : public Pad, public Instance
{
public:
    void takeDamage(float amount);
};
static Reflection::BoundFuncDesc<Instance, void(float), 1> func_takeDamage(static_cast<void (Instance::*)(float)>(&Humanoid::takeDamage), "TakeDamage", "amount", Reflection::FunctionDescriptor::None);
}
