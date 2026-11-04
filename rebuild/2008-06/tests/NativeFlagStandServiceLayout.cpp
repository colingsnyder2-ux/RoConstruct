#include "v8tree/Instance.h"
#include <list>
#define private public
#include "v8datamodel/FlagStandService.h"
#undef private
#include <stddef.h>
typedef char size_check[sizeof(RBX::FlagStandService)==0x14c?1:-1];
typedef char list_check[offsetof(RBX::FlagStandService,flagStands)==0x130?1:-1];
