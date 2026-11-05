// from server: 100% by EspClaude
// from server: 59% by colin
// from server: 56% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_dac953f05927d5ae.cpp

// Candidate translation unit (score above; library headers required).
#include "App/v8datamodel/PVInstance.cpp"

namespace RBX {

PVInstance* PVInstance::getTopLevelPVParent()
{
	PVInstance* p = this;
	while (!p->isTopLevelPVInstance())
		p = static_cast<PVInstance*>(p->getParent());
	return p;
}

}
