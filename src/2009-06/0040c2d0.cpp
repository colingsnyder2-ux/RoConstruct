// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_1b7d2e86b8427afb.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Utilities.h"
#include <vector>

namespace RBX {
namespace Reflection {
class PropertyDescriptor;
class DescribedBase { public: virtual ~DescribedBase(); char dpad[0x2c]; };
}
class Instance;
struct ChildRemoved
{
	const boost::shared_ptr<Instance> child;
	ChildRemoved(const boost::shared_ptr<Instance>& child) : child(child) {}
};
struct AncestorChanged
{
	Instance* const child;
	Instance* const oldParent;
	Instance* const newParent;
	AncestorChanged(Instance* child, Instance* oldParent, Instance* newParent)
		: child(child), oldParent(oldParent), newParent(newParent) {}
};
struct Property
{
	const Reflection::PropertyDescriptor* descriptor;
	Reflection::DescribedBase* instance;
	Property(const Reflection::PropertyDescriptor* d, Reflection::DescribedBase* i) : descriptor(d), instance(i) {}
};
void propertyChangedSlot(const Reflection::PropertyDescriptor* d);
struct PropBind { void (*f)(const Reflection::PropertyDescriptor*); const Reflection::PropertyDescriptor* d; };
class PropSignal { public: void fire(PropBind b); };
class ChildRemovedNotifier { public: void raise(ChildRemoved event); char npad[0x10]; };
class InstanceBase0 { public: virtual ~InstanceBase0(); char bpad[0x14]; };

extern Reflection::PropertyDescriptor propParent;

class Instance : public InstanceBase0, public Reflection::DescribedBase
{
public:
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
	virtual void onAncestorChanged(const AncestorChanged& event); // 7
	virtual void v8(); virtual void v9(); virtual void v10();
	virtual void onChildRemoving(Instance* child); // 11
	virtual void v12();
	virtual void onChildChanged(Instance* child, const Property& event); // 13
	virtual void onPropertyChanged(const Reflection::PropertyDescriptor& descriptor); // 14

	void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor)
	{
		Property event(&descriptor, this);
		onPropertyChanged(descriptor);
		PropSignal* sig = propSignal;
		PropBind b = { &propertyChangedSlot, &descriptor };
		if (sig) sig->fire(b);
		Instance* parent = this->parent;
		if (parent != NULL)
			parent->onChildChanged(this, event);
	}
	static void signalDescendentRemoving(const boost::shared_ptr<Instance>& instance, Instance* beginParent, Instance* newParent);
	void predelete();

	Instance* parent; // 0x48
	CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > children; // 0x4c
	std::string name; // 0x54
	char ipad[8];
	ChildRemovedNotifier childRemovedNotifier; // 0x78
	PropSignal* propSignal; // 0x88
};

void ool(Instance* i, const Reflection::PropertyDescriptor& d) { i->raisePropertyChanged(d); }
void Instance::predelete()
{
	while (children) {
		boost::shared_ptr<Instance> child;
		{
			boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > c = children.write();
			child = *(c->end() - 1);
			signalDescendentRemoving(child, this, NULL);
			this->onChildRemoving(child.get());
			child->parent = NULL;
			c->pop_back();
			if (c->empty()) {
				children.reset();
			}
		}
		childRemovedNotifier.raise(ChildRemoved(child));
		child->onAncestorChanged(AncestorChanged(child.get(), this, NULL));
		child->raisePropertyChanged(propParent);
	}
}
}
