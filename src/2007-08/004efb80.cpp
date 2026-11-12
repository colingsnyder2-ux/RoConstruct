// from server: 62% by EspClaude
// roc-flags: /O2 /GS /EHs /MD
// roc 2007-08 004efb80  unit: RBX::Render::VChunk::?$WeakReferenceCountedPointer  size: 122 bytes
// Uninitialized copy of weak reference-counted pointers (std::_Uninit_copy shape, try/catch frame).
// Target: edi=[esp+0x30] first, ebp=[esp+0x34] last, esi=[esp+0x38] dest; per element
// *dest=0; if (p=*first) { *dest=p; InterlockedIncrement(p+4) } via IAT.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Counted {
    int vtbl;
    long refs;
};

class WeakPtr {
public:
    Counted* p;
    WeakPtr(const WeakPtr& o) : p(0)
    {
        if (o.p) {
            p = o.p;
            InterlockedIncrement(&p->refs);
        }
    }
    ~WeakPtr();
};

inline void* operator new(unsigned int, void* where) { return where; }

WeakPtr* uninit_copy(WeakPtr* first, WeakPtr* last, WeakPtr* dest)
{
    WeakPtr* next = dest;
    try {
        for (; first != last; ++dest, ++first)
            new ((void*)dest) WeakPtr(*first);
    } catch (...) {
        for (; next != dest; ++next)
            next->~WeakPtr();
        throw;
    }
    return dest;
}
