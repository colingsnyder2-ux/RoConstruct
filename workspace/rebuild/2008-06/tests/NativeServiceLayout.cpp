#include "../native-headers/v8tree/Service.h"
#include <cstddef>
typedef char ServiceProviderSize[sizeof(RBX::ServiceProvider) == 0x1c8 ? 1 : -1];
typedef char ServiceArrayOffset[offsetof(RBX::ServiceProvider, serviceArray) == 0x190 ? 1 : -1];
typedef char ServiceMapOffset[offsetof(RBX::ServiceProvider, serviceMap) == 0x1a8 ? 1 : -1];
