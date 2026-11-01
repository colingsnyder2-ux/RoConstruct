#include "../native-headers/util/GuidItem.h"
namespace RBX { class Instance; }
typedef char GuidSize[sizeof(RBX::Guid) == 8 ? 1 : -1];
typedef char GuidItemSize[sizeof(RBX::GuidItem<RBX::Instance>) == 0x10 ? 1 : -1];
