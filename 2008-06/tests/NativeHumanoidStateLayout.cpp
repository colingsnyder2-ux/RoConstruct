#include "../native-headers/humanoid/HumanoidState.h"
#include <stddef.h>
using RBX::HUMAN::HumanoidState;
// allocation sizes of the base-only subclasses (Seated/Dead/FallingDown 0xa0) and ctor 00643e00 stores.
typedef char StateSize[sizeof(HumanoidState) == 0xa0 ? 1 : -1];
typedef char StateHumanoid[offsetof(HumanoidState, humanoid) == 0x08 ? 1 : -1];
typedef char StateValue0c[offsetof(HumanoidState, value0c) == 0x0c ? 1 : -1];
typedef char StateFlag10[offsetof(HumanoidState, flag10) == 0x10 ? 1 : -1];
typedef char StateFlag11[offsetof(HumanoidState, flag11) == 0x11 ? 1 : -1];
typedef char StateArray14[offsetof(HumanoidState, array14) == 0x14 ? 1 : -1];
typedef char StateFloorFound[offsetof(HumanoidState, floorFound) == 0x20 ? 1 : -1];
typedef char StateFloorPart[offsetof(HumanoidState, floorPart) == 0x24 ? 1 : -1];
typedef char StateFloorTouch[offsetof(HumanoidState, floorTouchInWorld) == 0x2c ? 1 : -1];
typedef char StateSpeed38[offsetof(HumanoidState, speed38) == 0x38 ? 1 : -1];
typedef char StateSpeed3c[offsetof(HumanoidState, speed3c) == 0x3c ? 1 : -1];
typedef char StatePrevious[offsetof(HumanoidState, previous) == 0x40 ? 1 : -1];
typedef char StateCurrent[offsetof(HumanoidState, current) == 0x70 ? 1 : -1];
RBX::HitTestFilter* humanoidStateFilter(HumanoidState* state) { return state; }
