// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
class PartInstance;
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
    BoundFuncDesc(void (Class::*function)(G3D::Vector3, PartInstance*), const char* name, const char* arg1name, const char* arg2name, FunctionDescriptor::Security security);
    ~BoundFuncDesc();
};
}
class VBase { public: virtual ~VBase(); };
class Instance : public virtual VBase { public: virtual ~Instance(); };
class Pad { public: virtual ~Pad(); char pad[0x13c - 4]; };
class Humanoid : public Pad, public Instance
{
public:
    void moveTo(G3D::Vector3 location, PartInstance* part);
};
static Reflection::BoundFuncDesc<Instance, void(G3D::Vector3, PartInstance*), 2> func_moveTo(static_cast<void (Instance::*)(G3D::Vector3, PartInstance*)>(&Humanoid::moveTo), "MoveTo", "location", "part", Reflection::FunctionDescriptor::None);
}
