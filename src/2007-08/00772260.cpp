// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_part_legacy_672da0f618a20cc7.cpp

// Candidate translation unit (score above; library headers required).
// 00577700 constructor RTTI proves PropDescriptor<PartInstance,bool>.
// Getter targets00573850/004cfe40 return one-byte booleans; setters005782f0/00578320 consume one stack argument.
// The newer header removed these nonvirtual methods. Restore declarations only; no fields or bases change.
#include "v8world/Primitive.h"
#define getCanCollide getCastsShadows() const; void setCastsShadows(bool); bool getCullable() const; void setCullable(bool); bool getCanCollide
#include "v8datamodel/PartInstance.h"
#undef getCanCollide
namespace RBX {
static Reflection::PropDescriptor<PartInstance,bool> recoveredCastsShadows("CastsShadows", "Appearance", &PartInstance::getCastsShadows, &PartInstance::setCastsShadows, Reflection::PropertyDescriptor::STANDARD);
static Reflection::PropDescriptor<PartInstance,bool> recoveredCullable("Cullable", "Appearance", &PartInstance::getCullable, &PartInstance::setCullable, Reflection::PropertyDescriptor::STANDARD);
}
