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

struct Functor {
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long d;
    Control* control;
};

struct TypeInfo {
    unsigned long data;
};

extern TypeInfo functorType;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);

void __cdecl manage(const Functor* source, Functor* destination, int operation)
{
    if (operation == 0) {
        if (destination) {
            destination->a = source->a;
            destination->b = source->b;
            destination->c = source->c;
            destination->d = source->d;
            destination->control = source->control;
            if (destination->control)
                _InterlockedIncrement(&destination->control->strong);
        }
    } else if (operation == 1) {
        Control* p = destination->control;
        if (p && _InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    } else {
        const TypeInfo* type = *reinterpret_cast<const TypeInfo**>(destination);
        *reinterpret_cast<const Functor**>(destination) =
            typeEqual(type, functorType) ? source : 0;
    }
}
