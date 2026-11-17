// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 005e6040: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8kernel/Body2008.h"
#include "v8world/Primitive2008.h"
#include "v8world/Joints2008.h"

void __cdecl update(struct Body* a, struct Joint* j, struct Body* c)
{
	RBX::Primitive* parentPrim = reinterpret_cast<RBX::Primitive*>(a);
	RBX::Primitive* childPrim = reinterpret_cast<RBX::Primitive*>(c);
	RBX::RigidJoint* joint = reinterpret_cast<RBX::RigidJoint*>(j);
	childPrim->getBody()->setMeInParent(joint->getChildInParent(parentPrim, childPrim));
}
