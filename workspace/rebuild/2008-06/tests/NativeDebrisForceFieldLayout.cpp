// Layout and instantiation probe for the inactive native DebrisService / ForceField headers.
// tests/record_native_debris_forcefield.py checks each size function is `mov eax, imm32; ret` with the allocation size
// the binary passes to malloc, and compares the instantiated creators with the original:
//   sizeof(DebrisService)   0x158  Creatable<Instance>::create<DebrisService> 005c2e10
//   sizeof(ForceField)      0x148  Creatable<Instance>::create<ForceField> 005c1520
// Field offsets are compile-time asserts (NativeDebrisForceFieldLayout is a friend of each class).
#include <stddef.h>
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/ForceField.h"

struct NativeDebrisForceFieldLayout
{
	typedef char DebrisQueue[offsetof(RBX::DebrisService, queue) == 0x130 ? 1 : -1];
	typedef char DebrisMaxItems[offsetof(RBX::DebrisService, maxItems) == 0x150 ? 1 : -1];
	typedef char DebrisTimer[offsetof(RBX::DebrisService, timer) == 0x154 ? 1 : -1];
	typedef char ForceFieldRendered[offsetof(RBX::ForceField, rendered) == 0x140 ? 1 : -1];
	typedef char ForceFieldCycle[offsetof(RBX::ForceField, sparkleCycle) == 0x144 ? 1 : -1];
};

size_t nativeDebrisServiceSize() { return sizeof(RBX::DebrisService); }
size_t nativeForceFieldSize() { return sizeof(RBX::ForceField); }

// The original emits these creators in the units that first create each class.
template boost::shared_ptr<RBX::DebrisService> RBX::Creatable<RBX::Instance>::create<RBX::DebrisService>();
template boost::shared_ptr<RBX::ForceField> RBX::Creatable<RBX::Instance>::create<RBX::ForceField>();
