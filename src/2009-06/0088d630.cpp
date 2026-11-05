// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeVBase { virtual ~ExeVBase(); };
struct V3 { int v; };
class Owner : public virtual ExeVBase {
};
struct ExePad { virtual ~ExePad(); char pad[0xa8]; };
class Accoutrement : public ExePad, public Owner {
public:
    V3 getAttachmentForward() const;
    void setAttachmentForward(V3);
};
namespace Reflection {
template<class C, class V>
class PropDescriptor {
public:
    template<class Getter, class Setter>
    PropDescriptor(const char* name, const char* category, Getter getter, Setter setter, int f);
    ~PropDescriptor();
private:
    char data[0x50];
};
}
typedef V3 (Owner::*G)() const;
typedef void (Owner::*S)(V3);
static Reflection::PropDescriptor<Owner, V3> prop_AttachmentForward("AttachmentForward", "Appearance", static_cast<G>(&Accoutrement::getAttachmentForward), static_cast<S>(&Accoutrement::setAttachmentForward), 1);
}
