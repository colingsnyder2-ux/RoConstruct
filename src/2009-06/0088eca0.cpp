// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class ClassDescriptor;
struct Member { ~Member(); };
class SignalDescriptor {
public:
    SignalDescriptor(const ClassDescriptor& c, const char* name);
    virtual ~SignalDescriptor() {}
    char pad[0x10];
    Member m;
};
template<class C, class Sig>
class __declspec(novtable) SignalDescBase : public SignalDescriptor {
protected:
    Sig C::* sig;
    SignalDescBase(Sig C::* s, const char* name) : SignalDescriptor(C::classDescriptor(), name), sig(s) {}
};
template<class C, class Sig>
class SignalDesc : public SignalDescBase<C, Sig> {
public:
    SignalDesc(Sig C::* s, const char* name) : SignalDescBase<C, Sig>(s, name) {}
    virtual ~SignalDesc() {}
};
}
struct Signal { int x; };
struct VB { int v; };
class Target : public virtual VB {
public:
    static const Reflection::ClassDescriptor& classDescriptor();
    char pad[0x228 - 4];
    Signal received;
};
static Reflection::SignalDesc<Target, Signal> event_OutfitChanged(&Target::received, "OutfitChanged");
}
