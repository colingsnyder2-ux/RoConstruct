// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeVBase { virtual ~ExeVBase(); };
struct CF { int v; };
class Owner : public virtual ExeVBase {
};
struct ExePad { virtual ~ExePad(); char pad[0xa8]; };
class Accoutrement : public ExePad, public Owner {
public:
    CF getAttachmentPoint() const;
    void setAttachmentPoint(CF);
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
typedef CF (Owner::*G)() const;
typedef void (Owner::*S)(CF);
static Reflection::PropDescriptor<Owner, CF> prop_AttachmentPoint("AttachmentPoint", "Appearance", static_cast<G>(&Accoutrement::getAttachmentPoint), static_cast<S>(&Accoutrement::setAttachmentPoint), 6);
}
