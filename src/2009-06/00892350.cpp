// from server: 100% by EspClaude
// static SignalDesc initializer
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
class SignalDesc : public SignalDescriptor {
    Sig C::* sig;
public:
    SignalDesc(Sig C::* s, const char* name) : SignalDescriptor(C::classDescriptor(), name), sig(s) {}
    virtual ~SignalDesc() {}
};
}
struct Signal { int x; };
class Target {
public:
    static const Reflection::ClassDescriptor& classDescriptor();
    char pad[0xcc];
    Signal sig_Button1Down;
};
static Reflection::SignalDesc<Target, Signal> event_Button1Down(&Target::sig_Button1Down, "Button1Down");
}
