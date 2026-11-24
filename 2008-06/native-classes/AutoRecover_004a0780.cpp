// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: all types below are local reconstructions; the real headers were not provided.
#include <typeinfo>

namespace RBX {
namespace Reflection {

struct ValueHolder {
    virtual ~ValueHolder() {}                 // slot 0: deleting destructor
    virtual void slot1() {}
    virtual ValueHolder* clone() const = 0;   // slot 2
};

class Value {
public:
    const void* type;
    ValueHolder* holder;
    Value(const Value& o)
        : type(o.type), holder(o.holder ? o.holder->clone() : 0)
    {
    }
    ~Value() { if (holder) delete holder; }

    template<class T> T& convert();
};

} // namespace Reflection
} // namespace RBX

struct Instance {
    virtual ~Instance() {}
};

struct OtherBase {
    virtual void ob() {}
};

// INFERRED: multiple inheritance so the member function pointer is {fn, adjustor}
struct Target : public Instance, public OtherBase {
    void set(int);
};

// INFERRED: argument source object; vtable slot 1 fills a Value
struct ArgSource {
    virtual void slot0() {}
    virtual void get(int index, RBX::Reflection::Value* out) = 0;
};

// INFERRED: bound property setter: member function pointer plus a stored default Value
struct BoundSetter {
    char pad[0x38];
    void (Target::*setter)(int);              // +0x38 fn, +0x3c adjustor
    RBX::Reflection::Value value;             // +0x40
};

extern "C" void __fastcall fn_004a0780(BoundSetter* self, int unusedEdx, Instance* arg1, ArgSource* arg2)
{
    RBX::Reflection::Value v(self->value);
    arg2->get(1, &v);
    Target* t = dynamic_cast<Target*>(arg1);
    if (!t)
        throw std::bad_cast("bad cast");
    (t->*(self->setter))(v.convert<int>());
}
