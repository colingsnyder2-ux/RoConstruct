// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); char pad[0xa8]; };
class Listener { public: virtual void onEvent(Instance* x) = 0; };
class Handler { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void handle(Instance* x); };
class Owner { char pad[0x13c]; public: Handler handler; };
void notifyParts(Instance* self, Instance* x);
Owner* findOwner(Instance* self);
class C : public Instance, public Listener {
public:
    virtual void onEvent(Instance* x);
};
void C::onEvent(Instance* x)
{
    notifyParts(this, x);
    if (Owner* o = findOwner(this))
        o->handler.handle(x);
}
}
