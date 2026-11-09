// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
namespace RBX {
class IStage { public: enum StageType { KERNEL_STAGE = 15 }; virtual ~IStage(); virtual StageType getStageType() const = 0; };
class __declspec(novtable) IPipelined {
public:
	virtual ~IPipelined() {}
	bool inKernel() const { return currentStage && currentStage->getStageType() == IStage::KERNEL_STAGE; }
	IStage* currentStage;
};
class Joint : public IPipelined {
public:
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
	virtual bool isBroken() const;
};
class Primitive;
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
    char pad2[0x54 - 0x32];
    std::set<Joint*> breakableJoints;
    void destroyJoint(Joint* j)
    {
        inJointNotification = true;
        Notifier<World, AutoDestroy>::raise(AutoDestroy(j));
        inJointNotification = false;
    }
    void doBreakJoints();
};
void World::doBreakJoints()
{
	std::set<Joint*>::iterator it = breakableJoints.begin();
	while (it != breakableJoints.end()) {
		Joint* joint = *it;
		++it;
		if (joint->inKernel() && joint->isBroken()) {
			destroyJoint(joint);
		}
	}
}
}
