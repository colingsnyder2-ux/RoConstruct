// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8kernel/Body.h"

namespace RBX
{
	void Body::onChildAdded(Body* child)
	{
		// makeCofmDirty() inlined once; only the recursive parent call stays a call.
		// INFERRED: Cofm dirty flag is the byte at +4, SimBody dirty flag is the byte at +8
		// (raw byte offsets, since those members are not visible in the headers).
		if (!cofm || !((char*)cofm)[4])
		{
			if (parent)
				parent->makeCofmDirty();
			else if (simBody)
				((char*)simBody)[8] = 1;
			if (cofm)
				((char*)cofm)[4] = 1;
		}

		// INFERRED: IndexArray::fastAppend stores the index in the child (+0x18) then appends to the G3D::Array.
		children.fastAppend(child);

		if (cofm == NULL)
		{
			cofm = new Cofm(this);
		}
	}
}
