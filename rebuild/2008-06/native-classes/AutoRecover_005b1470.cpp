// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x005b1470 is the compiler-generated vtordisp{-4,0} thunk
// (sub ecx,[ecx-4]; jmp 0x5b0fa0). It cannot be written in C++ source.
// MSVC emits it automatically for the virtual override
// Accoutrement::onCameraNear(float), which is the real body at 0x005b0fa0
// that the thunk jumps to. So only that override is defined here.
// INFERRED: ICameraSubject is assumed to be declared via Accoutrement.h (its base
// class), so no separate ICameraSubject include is used (that path does not exist).
#include "v8datamodel/Accoutrement.h"

namespace RBX
{
	void Accoutrement::onCameraNear(float distance)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (ICameraSubject* subject = dynamic_cast<ICameraSubject*>(getChild(i)))
				subject->onCameraNear(distance);
		}
	}
}
