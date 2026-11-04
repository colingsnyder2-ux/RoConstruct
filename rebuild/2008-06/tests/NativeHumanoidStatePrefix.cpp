#include "../native-headers/humanoid/HumanoidState.h"
#include <stddef.h>
typedef char StatePrefixSize[sizeof(RBX::HUMAN::HumanoidState) == 0x14 ? 1 : -1];
typedef char HumanoidOffset[offsetof(RBX::HUMAN::HumanoidState, humanoid) == 8 ? 1 : -1];
typedef char ValueOffset[offsetof(RBX::HUMAN::HumanoidState, value0c) == 0xc ? 1 : -1];
typedef char FlagOneOffset[offsetof(RBX::HUMAN::HumanoidState, flag10) == 0x10 ? 1 : -1];
typedef char FlagTwoOffset[offsetof(RBX::HUMAN::HumanoidState, flag11) == 0x11 ? 1 : -1];
RBX::HitTestFilter* humanoidFilter(RBX::HUMAN::HumanoidState* state) { return state; }
