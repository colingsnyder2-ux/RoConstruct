// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeVBase { virtual ~ExeVBase(); };
struct V { int v; };
class Owner : public virtual ExeVBase {
};
struct ExePad { virtual ~ExePad(); char pad[0xa8]; };
class Derived : public ExePad, public Owner {
public:
    V getBackendAccoutrementState() const;
    void setBackendAccoutrementState(V);
};
namespace Reflection {
template<class C, class T>
class PropDescriptor {
public:
    template<class Getter, class Setter>
    PropDescriptor(const char* name, const char* category, Getter getter, Setter setter, int f);
    ~PropDescriptor();
private:
    char data[0x50];
};
}
typedef V (Owner::*G)() const;
typedef void (Owner::*S)(V);
static Reflection::PropDescriptor<Owner, V> prop_BackendAccoutrementState("BackendAccoutrementState", "Appearance", static_cast<G>(&Derived::getBackendAccoutrementState), static_cast<S>(&Derived::setBackendAccoutrementState), 2);
}
