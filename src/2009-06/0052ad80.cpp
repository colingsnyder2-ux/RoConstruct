// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <algorithm>
namespace RBX {
struct MeshPartKey { char data[0x21]; unsigned int serialize(void* buf, unsigned long size) const; };
unsigned int MeshPartKey::serialize(void* buf, unsigned long size) const {
 unsigned int keySize = 0x21;
 if (size > 0) { unsigned int len = std::min<unsigned int>(size, keySize); memcpy(buf, this, len); return len; }
 return size;
}
}
