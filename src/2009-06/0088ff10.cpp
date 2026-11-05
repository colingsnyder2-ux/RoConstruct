// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct VB { int v; };
struct Sig { int s; };
class C : public virtual VB { public: char pad[0xf8]; Sig sig; };
template<class T> class SignalDesc {
public:
    SignalDesc(Sig T::* m, const char* name, const char* arg);
    ~SignalDesc();
};
SignalDesc<C> event_Climbing(&C::sig, "Climbing", "speed");
