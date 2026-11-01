// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeVBase { virtual ~ExeVBase(); };
struct V { int v; };
class Owner : public virtual ExeVBase {
};
struct ExePad { virtual ~ExePad(); char pad[0x138]; };
class Derived : public ExePad, public Owner {
public:
    V getTorso() const;
    void setTorso(V);
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
static Reflection::PropDescriptor<Owner, V> prop_Torso("Torso", "Data", static_cast<G>(&Derived::getTorso), static_cast<S>(&Derived::setTorso), 1);
}
