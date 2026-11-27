// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct counted {
    virtual ~counted();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use; long weak;
    void weak_release() { if (_InterlockedDecrement(&weak) == 0) destroy(); }
};
struct WP {
    void* px; counted* pi;
    ~WP() { if (pi) pi->weak_release(); }
};
struct E { WP w; int pad[4]; };
template class std::vector<E>;
