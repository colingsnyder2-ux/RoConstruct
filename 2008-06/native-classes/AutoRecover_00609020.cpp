// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/PVInstance.h"

namespace RBX
{
	// 00609020: the body is empty. The compiler-generated member teardown gives the disassembly:
	//   legacyOffset (boost::scoped_ptr<CoordinateFrame>, +0x19c) -> operator delete,
	//   TopPVController (ComputeProp holding a G3D::ReferenceCountedPointer<Controller>, +0x170) ->
	//     InterlockedDecrement, zeroWeakPointers, virtual deleting dtor,
	//   then Instance::~Instance (0055a540).
	// INFERRED: no explicit statements are needed in the body; the members' destructors do the work.
	PVInstance::~PVInstance()
	{
	}
}
