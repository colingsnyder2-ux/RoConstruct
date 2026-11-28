// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct RefCount {
    long unused;
    volatile long count;
};

struct Argument {
    unsigned long value1;
    RefCount* ref1;
    unsigned long value2;
    RefCount* ref2;
    unsigned long unused;
};

// StringConverter<CoordinateFrame>::convertToValue (cdecl, returns bool)
extern "C" bool __cdecl fn_0060a2f0(void*);
// ContentProvider::CachedContent::~CachedContent (thiscall, ecx = &arg)
extern "C" void __fastcall fn_00422c60(Argument* self);

// INFERRED: unknown global at 0x00821ca0 (likely a vtable / type tag); only its address is stored
extern "C" void* g_00821ca0;

struct Payload {
    unsigned long first;
    unsigned long value1;
    RefCount* ref1;
    unsigned long value2;
    RefCount* ref2;

    __forceinline Payload(unsigned long, const Argument&);
};

__forceinline Payload::Payload(unsigned long value, const Argument& arg) {
    first = value;
    value1 = arg.value1;
    ref1 = arg.ref1;
    if (ref1)
        _InterlockedIncrement(&ref1->count);
    value2 = arg.value2;
    ref2 = arg.ref2;
    if (ref2)
        _InterlockedIncrement(&ref2->count);
}

// INFERRED: object layout (tag at +0, payload at +8)
struct S {
    void* tag;
    unsigned long unused;
    Payload payload;
};

// INFERRED: the five dwords after 'first' on the stack form a by-value Argument
extern "C" S* __fastcall fn_00492ea0(S* self, int unusedEdx, unsigned long first, Argument arg) {
    self->tag = 0;
    if (!fn_0060a2f0(&first)) {
        new (&self->payload) Payload(first, arg);
        self->tag = &g_00821ca0;
        fn_00422c60(&arg);
        return self;
    }
    self->tag = 0;
    fn_00422c60(&arg);
    return self;
}
