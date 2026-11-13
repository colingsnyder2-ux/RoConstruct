#include <stddef.h>
#include "util/Http.h"

typedef char HttpUrlOffset[offsetof(RBX::Http, url) == 0 ? 1 : -1];
typedef char HttpHeadersOffset[offsetof(RBX::Http, additionalHeaders) == 0x1c ? 1 : -1];
typedef char HttpSize[sizeof(RBX::Http) == 0x38 ? 1 : -1];
