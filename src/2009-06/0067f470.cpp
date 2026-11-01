// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Joint;
class World;
struct AutoDestroy { Joint* joint; AutoDestroy(Joint* j) : joint(j) {} };
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
struct AutoJoin { Joint* joint; };

class World : public Notifier<World, AutoJoin>, public Notifier<World, AutoDestroy> {
public:
    char pad[0x31 - 8];
    bool inJointNotification;
    void destroyJoint(Joint* j);
};
void World::destroyJoint(Joint* j)
{
    inJointNotification = true;
    Notifier<World, AutoDestroy>::raise(AutoDestroy(j));
    inJointNotification = false;
}
}
