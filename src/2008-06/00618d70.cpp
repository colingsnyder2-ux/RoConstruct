// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct TypeInfo {
    unsigned long data;
};

extern const TypeInfo targetType;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);

struct RefCount {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Storage {
    void* value;
    unsigned long reserved[4];
    RefCount* control;

    void __thiscall copy(void*);
};

void __cdecl manage(void* destination, Storage* source, int operation)
{
    if (operation == 0) {
        if (source)
            source->copy(destination);
    } else if (operation == 1) {
        RefCount* control = source->control;
        if (control && _InterlockedDecrement(&control->strong) == 0) {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    } else {
        source->value =
            typeEqual(static_cast<const TypeInfo*>(source->value), targetType)
            ? destination : 0;
    }
}
