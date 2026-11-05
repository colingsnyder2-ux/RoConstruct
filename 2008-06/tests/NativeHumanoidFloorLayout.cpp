#include "../native-headers/humanoid/HumanoidFloorFields.h"
#include <stddef.h>
using RBX::HUMAN::HumanoidFloorFields;
typedef char FloorSize[sizeof(HumanoidFloorFields)==0x80 ? 1 : -1];
typedef char FloorActive[offsetof(HumanoidFloorFields,active)==0 ? 1 : -1];
typedef char FloorPart[offsetof(HumanoidFloorFields,floorPart)==4 ? 1 : -1];
typedef char FloorTouch[offsetof(HumanoidFloorFields,floorTouchInWorld)==0xc ? 1 : -1];
typedef char FloorPrevious[offsetof(HumanoidFloorFields,previous)==0x20 ? 1 : -1];
typedef char FloorCurrent[offsetof(HumanoidFloorFields,current)==0x50 ? 1 : -1];
