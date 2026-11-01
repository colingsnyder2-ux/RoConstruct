// from server: 100% by EspClaude
// from server: 81% by EspClaude
// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_138a10b29f1d98e0.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance; template<typename Class> boost::shared_ptr<Class> shared_from(Class*); template<> boost::shared_ptr<Instance> shared_from<Instance>(Instance*); template<> boost::shared_ptr<const Instance> shared_from<const Instance>(const Instance*); }
#include <v8datamodel/Selection.h>
namespace RBX {
	struct SelectionExe2009 { void listenTo(Instance*); };
	void Selection::addToSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = (*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x8c)).write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared);

		if (found == sel->end())
		{
			sel->push_back(shared);
			reinterpret_cast<SelectionExe2009*>(this)->listenTo(shared.get());
			raiseAdded(shared);
		}
	}
}
