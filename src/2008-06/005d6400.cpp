// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_a000eb035600a171.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Teams.h"
namespace RBX {
void Teams::onChildRemoving(Instance* child)
	{
		if (dynamic_cast<Team*>(child))
		{
			boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>>& myTeams = reinterpret_cast<CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*>(reinterpret_cast<char*>(this) + 0x130)->write();
			myTeams->erase(std::find(myTeams->begin(), myTeams->end(), shared_from(child)));
		}
	}

	
}
