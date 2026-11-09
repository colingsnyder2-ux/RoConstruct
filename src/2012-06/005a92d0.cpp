// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
#include <vector>

// element size 6 from target lea [esi+esi*2] / [edi+ecx*2]
struct Elem6 {
    short a, b, c;
};

template class std::vector<Elem6>;
