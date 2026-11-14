// Layout probe for the inactive native Humanoid2008.h; tests/record_native_humanoid2008.py checks each function body
// is `mov eax, imm32; ret` with the value read from the binary:
//   sizeof(Humanoid)        0x22c  Creatable<Instance>::create<Humanoid> 00490770 mallocs 0x22c
//   Connector base          0x130  constructor 005db280 stores the Connector vtable 0083d3e0 at +0x130
//   IControllable base      0x138  (vtable 0083d3d4)
//   IRenderable base        0x13c  (vtable 0083d3bc)
//   ICharacterSubject base  0x14c  (vtable 0083d388; ICharacterSubject() 00641320 called on +0x14c)
//   IModelModifier base     0x1a0  (vtable 0083d380)
//   Listener base           0x1a4  (vtable 0083d374)
//   ILocation virtual base  0x228  (vtable 0083d36c stored through the vbtable at +0x150: 0x150 + 0xd8)
// Field offsets are compile-time asserts (NativeHumanoid2008Layout is a friend of Humanoid); the offsets come from
// the constructor 005db280 and destructor 005d7d20 field writes and the getters named in Humanoid2008.h.
#include <stddef.h>
#include "humanoid/Humanoid2008.h"

struct NativeHumanoid2008Layout
{
	typedef char Health[offsetof(RBX::Humanoid, health) == 0x1a8 ? 1 : -1];
	typedef char MaxHealth[offsetof(RBX::Humanoid, maxHealth) == 0x1ac ? 1 : -1];
	typedef char WalkRotationalVelocity[offsetof(RBX::Humanoid, walkRotationalVelocity) == 0x1b0 ? 1 : -1];
	typedef char WalkTimer[offsetof(RBX::Humanoid, walkTimer) == 0x1b4 ? 1 : -1];
	typedef char WalkMode[offsetof(RBX::Humanoid, walkMode) == 0x1b8 ? 1 : -1];
	typedef char WalkToPart[offsetof(RBX::Humanoid, walkToPart) == 0x1bc ? 1 : -1];
	typedef char WalkToPoint[offsetof(RBX::Humanoid, walkToPoint) == 0x1c4 ? 1 : -1];
	typedef char WalkDirection[offsetof(RBX::Humanoid, walkDirection) == 0x1d0 ? 1 : -1];
	typedef char TargetPoint[offsetof(RBX::Humanoid, targetPoint) == 0x1dc ? 1 : -1];
	typedef char Head[offsetof(RBX::Humanoid, head) == 0x1ec ? 1 : -1];
	typedef char Torso[offsetof(RBX::Humanoid, torso) == 0x1f4 ? 1 : -1];
	typedef char LeftLeg[offsetof(RBX::Humanoid, leftLeg) == 0x1fc ? 1 : -1];
	typedef char RightLeg[offsetof(RBX::Humanoid, rightLeg) == 0x204 ? 1 : -1];
	typedef char RightArm[offsetof(RBX::Humanoid, rightArm) == 0x20c ? 1 : -1];
	typedef char LeftArm[offsetof(RBX::Humanoid, leftArm) == 0x214 ? 1 : -1];
	typedef char World[offsetof(RBX::Humanoid, world) == 0x21c ? 1 : -1];
	typedef char CurrentState[offsetof(RBX::Humanoid, currentState) == 0x220 ? 1 : -1];
};

#define NATIVE_HUMANOID_BASE(fn, Base) \
	size_t fn() { return (size_t)static_cast<Base*>((RBX::Humanoid*)0x1000) - 0x1000; }

size_t nativeHumanoid2008Size() { return sizeof(RBX::Humanoid); }
NATIVE_HUMANOID_BASE(nativeHumanoid2008Connector, RBX::Connector)
NATIVE_HUMANOID_BASE(nativeHumanoid2008Controllable, RBX::IControllable)
NATIVE_HUMANOID_BASE(nativeHumanoid2008Renderable, RBX::IRenderable)
NATIVE_HUMANOID_BASE(nativeHumanoid2008CharacterSubject, RBX::ICharacterSubject)
NATIVE_HUMANOID_BASE(nativeHumanoid2008ModelModifier, RBX::IModelModifier)
size_t nativeHumanoid2008Listener()
{
	return (size_t)static_cast<RBX::Listener<RBX::RunService, RBX::Stepped>*>((RBX::Humanoid*)0x1000) - 0x1000;
}
size_t nativeHumanoid2008Instance() { return sizeof(RBX::Instance); }
