// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT
#include "v8datamodel/Selection.h"
#include <algorithm>

namespace RBX {
	// 00424eb0
	bool Selection::isSelected(const Instance* instance) const
	{
		return std::find(selection->begin(), selection->end(), shared_from(instance)) != selection->end();
	}
}
