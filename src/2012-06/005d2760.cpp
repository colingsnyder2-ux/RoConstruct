// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
#include <algorithm>

struct MeshKeyBase { char data[44];

  size_t get(void* dst, size_t n) const {
    size_t k = 61;
    if (n > 0) { size_t t = n; size_t m = std::min(t, k); memcpy(dst, data, m); return m; }
    return n; } };
size_t f(MeshKeyBase* k, void* d, size_t n) { return k->get(d, n); }
