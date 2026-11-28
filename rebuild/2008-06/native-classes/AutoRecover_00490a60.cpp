// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0082175c[];
#include <new>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Local_00490a60_RefCount {
    long unused;
    volatile long count;
};

// ContentProvider::CachedContent::~CachedContent (thiscall)
extern "C" void __fastcall fn_00422c60(void* self, int unusedEdx);
// StringConverter<CoordinateFrame>::convertToValue (cdecl)
extern "C" bool __cdecl fn_0060a2f0(void*);

struct Local_00490a60_Payload {
    unsigned long first;
    unsigned long value1;
    Local_00490a60_RefCount* ref1;
    unsigned long value2;
    Local_00490a60_RefCount* ref2;

    __forceinline Local_00490a60_Payload(unsigned long f, unsigned long v1, Local_00490a60_RefCount* r1, unsigned long v2, Local_00490a60_RefCount* r2) {
        first = f;
        value1 = v1;
        ref1 = r1;
        if (ref1)
            _InterlockedIncrement(&ref1->count);
        value2 = v2;
        ref2 = r2;
        if (ref2)
            _InterlockedIncrement(&ref2->count);
    }
};

// INFERRED: object layout from analog (tag, unused, payload)
struct Local_00490a60_Self {
    unsigned long tag;
    unsigned long unused;
    Local_00490a60_Payload payload;
};

// INFERRED: six stack dwords: first, then a 5-dword argument whose tail is destroyed in place
extern "C" Local_00490a60_Self* __fastcall fn_00490a60(Local_00490a60_Self* self, int unusedEdx,
    unsigned long a0, unsigned long a1, Local_00490a60_RefCount* a2,
    unsigned long a3, Local_00490a60_RefCount* a4, unsigned long a5) {
    self->tag = 0;
    if (!fn_0060a2f0(&a0)) {
        new (&self->payload) Local_00490a60_Payload(a0, a1, a2, a3, a4);
        self->tag = (unsigned)g_0082175c;
        fn_00422c60(&a1, 0);
        return self;
    }
    self->tag = 0;
    fn_00422c60(&a1, 0);
    return self;
}
