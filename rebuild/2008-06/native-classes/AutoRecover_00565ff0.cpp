// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Accoutrement.h"

namespace RBX
{
	// INFERRED: askSetParent is defined inline in Accoutrement.h (ICF-folded with askAddChild at 00565ff0).
	// Taking its address forces the out-of-line copy: mov al,1 / ret 4.
	bool (Accoutrement::* const accoutrementAskSetParentAnchor)(const Instance*) const = (bool (Accoutrement::*)(const Instance*) const)0;
}
