// Ball contact deleting destructors for the inactive native Contact2008.h recovery (tests/record_native_world_shapes.py).
// The 2008 ??_GBallBallContact 0060cb70 / ??_GBallBlockContact 0060cbd0 (31 bytes) restore the vtable and free the
// object without the donor ~IPipelined RBXASSERT(currentStage == NULL), so this unit is compiled without
// _RELEASEASSERT (as native-classes/ContactManagerLifetime.cpp does). It is separate from NativeWorldShapesLayout.cpp,
// whose rows keep the document-swap profile. Constructing the two contacts emits their vtables, whose deleting
// destructor slots are the compared rows; the callers are analogs of the ball branches of ContactManager::createContact
// 0060d770 (which news 0x38 for both) and are not rows.
#undef _RELEASEASSERT
#include "v8world/Contact2008.h"

RBX::Contact* nativeWorldShapesContactDtorsBallBall(RBX::Primitive* p0, RBX::Primitive* p1)
{
	return new RBX::BallBallContact(p0, p1);
}

RBX::Contact* nativeWorldShapesContactDtorsBallBlock(RBX::Primitive* p0, RBX::Primitive* p1)
{
	return new RBX::BallBlockContact(p0, p1);
}
