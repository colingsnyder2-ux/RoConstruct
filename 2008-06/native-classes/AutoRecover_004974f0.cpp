// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: arg2 is a by-value boost::shared_ptr-style handle; the epilogue releases use/weak counts via vtable slots 1 and 2.
struct CountedBase {
    virtual ~CountedBase() {}
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long useCount;
    volatile long weakCount;
};

struct CountedRef {
    CountedBase* pi;
    ~CountedRef() {
        if (pi && _InterlockedDecrement(&pi->useCount) == 0) {
            pi->dispose();
            if (_InterlockedDecrement(&pi->weakCount) == 0)
                pi->destroy();
        }
    }
};

// INFERRED: source/target class types are not known; local polymorphic stand-ins.
struct SrcBase {
    virtual ~SrcBase() {}
};

struct RectHolder : SrcBase {
    char pad[0x1c8 - 4]; // INFERRED: padding to reach the rect fields
    short left;
    short top;
    short right;
    short bottom;
};

extern "C" void __fastcall fn_0048ae50(void* self, int unusedEdx, const float* rect);

extern "C" void __stdcall fn_004974f0(SrcBase* obj, CountedRef ref, void* target)
{
    RectHolder* h = dynamic_cast<RectHolder*>(obj);
    if (h) {
        float r[4];
        r[0] = (float)h->left;
        r[1] = (float)h->top;
        r[2] = (float)h->right;
        r[3] = (float)h->bottom;
        fn_0048ae50(target, 0, r);
    }
}
