// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <algorithm>
namespace RBX {
struct MeshTrussPartKey {
    char data[0x25];
    size_t copyTo(void* dst, size_t n) const;
};
size_t MeshTrussPartKey::copyTo(void* dst, size_t n) const
{
    size_t size = sizeof(data);
    if (n > 0) {
        size_t len = n;
        len = std::min(len, size);
        memcpy(dst, this, len);
        return len;
    }
    return n;
}
}
