// Layout and instantiation probe for the inactive native hit-test filters (native-headers/v8datamodel/Filters2008.h).
// tests/record_native_hit_filters.py checks each size function is `mov eax, imm32; ret`:
//   PartByLocalCharacter / UnlockedPartByLocalCharacter 0x14 (constructor 00660380 writes +0x04..+0x10),
//   FilterStairs 0x0c (constructor 006604a0 writes +0x04/+0x08), Unlocked / FilterCharacterOcclusion 4 (vtable only).
// Field offsets are compile-time asserts (NativeHitTestFilterLayout is a friend of the classes).
// nativeHitFilterInline builds the two filters whose constructors are inline so that this object carries the inline
// virtual Unlocked::filterResult (00615b60, emitted by the original in the MouseCommand unit) and the vtables of
// Unlocked (00843a48) and UnlockedPartByLocalCharacter (00843a50).
#include <stddef.h>
#include "v8datamodel/Filters2008.h"

struct NativeHitTestFilterLayout
{
	typedef char CharacterAt4[offsetof(RBX::PartByLocalCharacter, character) == 0x04 ? 1 : -1];
	typedef char HeadAtC[offsetof(RBX::PartByLocalCharacter, head) == 0x0c ? 1 : -1];
	typedef char ModelAt4[offsetof(RBX::FilterStairs, model) == 0x04 ? 1 : -1];
};

size_t nativePartByLocalCharacterSize() { return sizeof(RBX::PartByLocalCharacter); }
size_t nativeUnlockedPartByLocalCharacterSize() { return sizeof(RBX::UnlockedPartByLocalCharacter); }
size_t nativeFilterStairsSize() { return sizeof(RBX::FilterStairs); }
size_t nativeUnlockedSize() { return sizeof(RBX::Unlocked); }
size_t nativeFilterCharacterOcclusionSize() { return sizeof(RBX::FilterCharacterOcclusion); }

void nativeHitFilterUse(const RBX::HitTestFilter* a, const RBX::HitTestFilter* b);

void nativeHitFilterInline(RBX::Instance* root)
{
	RBX::Unlocked unlocked;
	RBX::UnlockedPartByLocalCharacter filter(root);
	nativeHitFilterUse(&unlocked, &filter);
}
