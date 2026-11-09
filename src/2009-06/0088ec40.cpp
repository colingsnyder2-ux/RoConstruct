// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct VB { int v; };
struct Sig { int s; };
class PartInstance : public virtual VB { public: char pad[0x218]; Sig touched; };
template<class C> class SignalDesc {
public:
    SignalDesc(Sig C::* m, const char* name, const char* arg);
    ~SignalDesc();
};
SignalDesc<PartInstance> event_LocalSimulationTouched(&PartInstance::touched, "LocalSimulationTouched", "part");
