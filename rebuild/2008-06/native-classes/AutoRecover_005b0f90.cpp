// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is the compiler-generated vtordisp thunk
// (sub ecx,[ecx-4]; jmp Accoutrement::getLocation @005b0b70). It is emitted
// automatically for the ILocation virtual-base override, so the only source
// to define is the real member below.
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// @005b0b70 (ILocation this): PartInstance::getCoordinateFrame 00598cb0, CoordinateFrame() 004782d0
	const G3D::CoordinateFrame Accoutrement::getLocation() const
	{
		const PartInstance* handle = getHandleConst();
		return handle ? handle->getCoordinateFrame() : G3D::CoordinateFrame();
	}
}
