// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
#include <vector>

namespace RBX { namespace Lua {
// Opaque: element stride 0x28 with int at +0x20 and only the 0x20-byte
// prefix assigned through an out-of-line call (0x6a6210).
struct WeakThreadRef {
    WeakThreadRef();
    WeakThreadRef(const WeakThreadRef &);
    ~WeakThreadRef();
    WeakThreadRef &operator=(const WeakThreadRef &);
    double storage[4];
};
} }

struct ThreadEntry {
    RBX::Lua::WeakThreadRef thread;
    int value;
};

template class std::vector<ThreadEntry>;
