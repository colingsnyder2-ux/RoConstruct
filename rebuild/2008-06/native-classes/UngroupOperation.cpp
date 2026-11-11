// >>> native-status (generated) -- do not edit >>>
// UngroupOperation | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src 04cb72ed | roc native-status --write
#include "../native-headers/v8tree/Instance.h"
#include <vector>

namespace RBX {

struct UngroupOperation {
	std::vector<Instance*>* children;
	bool* changed;
	UngroupOperation(std::vector<Instance*>& c, bool& b) : children(&c), changed(&b) {}
	void operator()(const boost::shared_ptr<Instance>&) const;
};

void UngroupOperation::operator()(const boost::shared_ptr<Instance>& item) const {
	if (item->numChildren() > 0) {
		for (unsigned int i = 0; i < item->numChildren(); ++i) {
			Instance* child = item->getChild(i);
			children->push_back(child);
		}
		item->removeAllChildren();
		item->setParent(NULL);
		*changed = true;
	}
}

}
