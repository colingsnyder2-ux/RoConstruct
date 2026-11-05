// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
#include <vector>

// element size 72 from target lea [esi+esi*8] / [edi+ecx*8]
struct Elem72 {
    float v[18];
};

template class std::vector<Elem72>;
