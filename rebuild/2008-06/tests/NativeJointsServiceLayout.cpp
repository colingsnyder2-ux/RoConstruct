#include "v8datamodel/JointsService.h"
#include <stddef.h>
// Donor declaration corroborated by listener adjustment -0x140 at 005e550d.
typedef char world_offset[offsetof(RBX::JointsService, world)==0x150?1:-1];
typedef char service_size[sizeof(RBX::JointsService)==0x154?1:-1];
