// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Buffer {
    void* object;
    void* auxiliary;
    Control* control;
};

struct TypeInfo {
    void* vtable;
};

typedef bool (__thiscall *TypeEqual)(const TypeInfo*, const TypeInfo&);
extern TypeEqual typeEqual;
extern const TypeInfo expectedType;

void __cdecl manager(const Buffer* source, Buffer* destination, int operation)
{
    if (operation == 0) {
        if (destination) {
            destination->object = source->object;
            destination->auxiliary = source->auxiliary;
            destination->control = source->control;
            if (destination->control)
                _InterlockedIncrement(&destination->control->strong);
        }
    } else if (operation == 1) {
        Control* control = destination->control;
        if (control && _InterlockedDecrement(&control->strong) == 0) {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    } else {
        destination->object =
            typeEqual(static_cast<const TypeInfo*>(destination->object), expectedType)
            ? const_cast<Buffer*>(source) : 0;
    }
}
