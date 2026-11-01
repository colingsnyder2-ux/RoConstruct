// from server: 100% by EspClaude
// from server: 85% by EspClaude
// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll roc_espclaude_8642f903dfe05da9.cpp

// Candidate translation unit (score above; library headers required).
#include "decomp.h"
#include "util/Utilities.h"
#include <vector>
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
namespace RBX {
class Instance {
public:
	virtual ~Instance();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void onDescendentRemoving(const shared_ptr<Instance>& instance);
	bool isAncestorOf(const Instance* descendent) const
	{
		if (descendent == NULL) {
			return false;
		}

		descendent = descendent->parent;

		if (descendent == this) {
			return true;
		}

		return isAncestorOf(descendent);
	}
private:
	static void signalDescendentRemoving(const shared_ptr<Instance>& instance, Instance* beginParent, Instance* newParent);
	char exePad[0x44];
	Instance* parent;
	CopyOnWrite<std::vector<shared_ptr<Instance> > > children;
};

void Instance::signalDescendentRemoving(
	const shared_ptr<Instance>& instance,
	Instance* beginParent,
	Instance* newParent
)
{
	for (Instance* walk = beginParent; walk != NULL; walk = walk->parent) {
		if (walk == newParent) {
			break;
		}

		if (walk->isAncestorOf(newParent)) {
			break;
		}

		walk->onDescendentRemoving(instance);
	}

	boost::shared_ptr<const std::vector<shared_ptr<Instance> > > c = instance->children.read();

	if (c) {
		for (std::vector<shared_ptr<Instance> >::const_iterator it = c->begin(); it != c->end(); ++it) {
			signalDescendentRemoving(*it, beginParent, newParent);
		}
	}
}
}
