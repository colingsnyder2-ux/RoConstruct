// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class PartInstance;
struct CanAggregateChanged { bool canAggregate; CanAggregateChanged(bool c) : canAggregate(c) {} };
template<class C, class E> struct Listener { virtual void onEvent(const C*, E) = 0; };
template<class C, class E> void callListener(Listener<C,E>* l, E e);
template<class C, class E> struct Binder { void (*f)(Listener<C,E>*, E); E e; Binder(void (*ff)(Listener<C,E>*, E), E ee) : f(ff), e(ee) {} };
struct ListenerSet { template<class F> void visit(F f); };
template<class C, class E>
class Notifier {
    ListenerSet* listeners;
public:
    void raise(E e) const { Binder<C,E> b(&callListener<C,E>, e); if (listeners) listeners->visit(b); }
};
class InstancePad { public: virtual ~InstancePad(); char d[0x98]; };
class IPrimitiveOwner { char data[0x8]; public: virtual void onCanAggregateChanged(bool canAggregate) = 0; };
class IRenderable { char data[0x4]; public: virtual ~IRenderable(); void shouldRenderSetDirty(); };
class PartPad { public: char d[0x210 - 0xb0]; };
class PartInstance : public InstancePad, public IPrimitiveOwner, public IRenderable, public PartPad,
                     public Notifier<PartInstance, CanAggregateChanged>
{
public:
    virtual void onCanAggregateChanged(bool canAggregate);
};
void PartInstance::onCanAggregateChanged(bool canAggregate)
{
    Notifier<PartInstance, CanAggregateChanged>::raise(canAggregate);
    shouldRenderSetDirty();
}
}
