// from server: 100% by EspClaude
#include <intrin.h>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    char* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct String {
    unsigned long reserved;
    union {
        char local[16];
        char* heap;
    } storage;
    unsigned long length;
    unsigned long capacity;
    ~String();
};

struct Error {
    char data[40];
    Error(const String&);
    Error(const Error&);
    ~Error();
};

struct Result {
    void* object;
    Control* control;
    ~Result();
};

extern Shared __cdecl acquire(void*, int);
extern Error __cdecl format(const char*, ...);
extern Result __cdecl assign(void*);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

Result __cdecl reconstruct(void* source, int index)
{
    Shared value = acquire(source, index);
    char* instance;

    if (value.object) {
        char* p = value.object;
        _ReadWriteBarrier();
        if (!__RTDynamicCast(p, 0, (void*)0x9291fc,
                            (void*)0x92907c, 0)) {
            String* name = *(String**)(*(char**)(p + 4) + 4);
            throw (format("Object %s is not an Instance",
                               name->capacity >= 16
                                   ? name->storage.heap
                                   : name->storage.local));
        }
        instance = p - 0x18;
    } else {
        instance = 0;
    }

    return assign(instance);
}
