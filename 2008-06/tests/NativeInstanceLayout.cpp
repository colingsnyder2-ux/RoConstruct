#include "../native-headers/v8tree/Instance.h"
#include <cstddef>
typedef char InstanceSize[sizeof(RBX::Instance) == 0x130 ? 1 : -1];
typedef char ParentOffset[offsetof(RBX::Instance, parent) == 0x104 ? 1 : -1];
typedef char AssociationOffset[offsetof(RBX::Instance, assoc) == 0xec ? 1 : -1];
