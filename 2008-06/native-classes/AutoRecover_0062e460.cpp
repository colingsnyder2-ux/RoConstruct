// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the vendor version is `RBXASSERT(world==NULL); RBXASSERT(part==NULL);`. Under /DNDEBUG both asserts
// compile away, so the body is empty. The compiler generates the teardown: the vtable stores, the
// weak_ptr<PartInstance> release at +0x144, the Connector base vtable store and the Instance::~Instance call.
// INFERRED: the 2008 Body is selected the same way as in the sibling BodyMovers.cpp. That file also adds
// -I<headers>/part-embedded through its native-flags, which this file does not.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/BodyMovers.h"

namespace RBX
{
	BodyMover::~BodyMover()
	{
	}
}
