// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Part {
    char padding[0x324];
    int value;
};

struct Control {
    virtual void slot0();
    virtual void dispose();
    virtual void destroy();

    volatile long strongCount;
    volatile long weakCount;
};

bool __cdecl f(Part* part, Control* control)
{
    bool result = part && part->value != 0;

    if (control) {
        if (_InterlockedDecrement(&control->strongCount) == 0) {
            control->dispose();
            if (_InterlockedDecrement(&control->weakCount) == 0)
                control->destroy();
        }
    }

    return result;
}
