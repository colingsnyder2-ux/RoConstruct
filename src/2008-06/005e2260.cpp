// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost { template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } }; }
namespace RBX {
class Instance;
class PropertyChanged;
class RunService { public: void invalidateRunViews(); };
struct Args { int x; };
struct Sig { void fire(Args&, bool); };
struct Slot { char pad[0x10]; Sig sig; };
struct SignalDesc { Slot* getSlot(Instance*); };
class Sky;
class Primary {
public:
    virtual ~Primary();
    void onChildChanged(Instance*, const PropertyChanged&);
    char pad[0x10];
};
class Instance {
public:
    virtual ~Instance();
};
template<class T> T* find(Primary*);
class Lighting : public Primary, public Instance {
public:
    char pad1[0x2d4 - 0x18];
    boost::shared_ptr<Sky> sky;
    static SignalDesc event_LightingChanged;
    void fireLightingChanged(bool b)
    {
        Args a;
        Slot* s = event_LightingChanged.getSlot(this);
        if (s)
            s->sig.fire(a, b);
    }
    virtual void onChildChanged(Instance*, const PropertyChanged&);
};
void Lighting::onChildChanged(Instance* instance, const PropertyChanged& event)
{
    Primary::onChildChanged(instance, event);
    if (sky.get() == (Sky*)instance) {
        fireLightingChanged(true);
        RunService* runService = find<RunService>(this);
        if (runService)
            runService->invalidateRunViews();
    }
}
}
