#include "v8tree/Instance.h"
#include <queue>
#define private public
#include "v8datamodel/DebrisService.h"
#undef private
#include <stddef.h>
typedef char size_check[sizeof(RBX::DebrisService)==0x158?1:-1];
typedef char queue_check[offsetof(RBX::DebrisService,queue)==0x130?1:-1];
typedef char max_check[offsetof(RBX::DebrisService,maxItems)==0x150?1:-1];
typedef char timer_check[offsetof(RBX::DebrisService,timer)==0x154?1:-1];
