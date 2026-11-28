// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0092907c[];   // INFERRED: unnamed global at 0x0092907c in the original
extern "C" char g_009291fc[];   // INFERRED: unnamed global at 0x009291fc in the original
#include <intrin.h>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Local_0061aac0_Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Local_0061aac0_Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Local_0061aac0_Shared {
    char* object;
    Local_0061aac0_Control* control;
    ~Local_0061aac0_Shared();
};

inline Local_0061aac0_Shared::~Local_0061aac0_Shared()
{
    if (control)
        control->release();
}

struct Local_0061aac0_String {
    unsigned long reserved;
    union {
        char local[16];
        char* heap;
    } storage;
    unsigned long length;
    unsigned long capacity;
    ~Local_0061aac0_String();
};

struct Local_0061aac0_Error {
    char data[40];
    Local_0061aac0_Error(const Local_0061aac0_String&);
    Local_0061aac0_Error(const Local_0061aac0_Error&);
    ~Local_0061aac0_Error();
};

struct Local_0061aac0_Result {
    void* object;
    Local_0061aac0_Control* control;
    ~Local_0061aac0_Result();
};

// INFERRED: signatures from the analog
extern "C" Local_0061aac0_Shared __cdecl fn_0061a4f0(void*, int);
extern "C" Local_0061aac0_String __cdecl fn_00509b10(const char*, ...);
extern "C" Local_0061aac0_Result __cdecl fn_00618a40(void*);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern "C" Local_0061aac0_Result __cdecl fn_0061aac0(void* source, int index)
{
    Local_0061aac0_Shared value = fn_0061a4f0(source, index);
    char* instance;

    if (value.object) {
        char* p = value.object;
        _ReadWriteBarrier();
        if (!__RTDynamicCast(p, 0, (void*)((int)&g_009291fc),
                            (void*)((int)&g_0092907c), 0)) {
            p = *(char**)(p + 8);
            Local_0061aac0_String* name = (Local_0061aac0_String*)(*(char**)(p + 4) + 4);
            throw Local_0061aac0_Error(fn_00509b10("Object %s is not an Instance",
                               name->capacity >= 16
                                   ? name->storage.heap
                                   : name->storage.local));
        }
        instance = p - 20;
    } else {
        instance = 0;
    }

    return fn_00618a40(instance);
}
