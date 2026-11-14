// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/JointInstance.h"

namespace RBX
{
	bool JointInstance::shouldRender3dAdorn() const
	{
		return PartInstance::showSpanningTree;
	}
}
