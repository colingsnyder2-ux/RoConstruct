// from server: 100% by EspClaude
// from server: 85% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_277ac2163fb35fc7.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <stddef.h>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
namespace RBX {
template<class Class>
boost::shared_ptr<Class> shared_from(Class* r)
{
	return r ? boost::shared_static_cast<Class>(r->shared_from_this()) : boost::shared_ptr<Class>();
}
class Instance;
struct ChildrenHolder { std::vector<boost::shared_ptr<Instance> > v; };
struct VEmpty {};
class Instance : public boost::enable_shared_from_this<Instance>, public virtual VEmpty {
public:
	virtual ~Instance();
	char pad0[0x108 - 0x10];
	ChildrenHolder* children;
	char pad1[0x268 - 0x10c];
	boost::shared_ptr<Instance> clone();
	size_t numChildren() const
	{
		if (children)
			return children->v.size();
		else
			return 0;
	}
};
class TimerService {
public:
	void delay(boost::function0<void> func, double seconds);
};
class Flag : public Instance {
public:
	boost::shared_ptr<Instance> evilClone;
	char pad2[0x288 - 0x270];
	TimerService* timer;
private:
	void doUglyPeriodicCloneHack();
};
typedef char chk1[(offsetof(Flag, evilClone) == 0x268) ? 1 : -1];
typedef char chk2[(offsetof(Flag, timer) == 0x288) ? 1 : -1];
typedef char chk3[(offsetof(Instance, children) == 0x108) ? 1 : -1];
void Flag::doUglyPeriodicCloneHack()
{
	evilClone = clone();

	if (timer && numChildren() == 0)
	{
		timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0f);
	}
}
}
