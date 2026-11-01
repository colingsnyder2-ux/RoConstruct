// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Argument
{
    unsigned long a;
    unsigned long b;
    unsigned long c;
    Control* control;
    unsigned long d;
    unsigned long e;
    unsigned long unused;
};

extern bool __cdecl func_0060a2f0();
extern unsigned char table_0080ee20[];

struct S
{
    void* type;
    unsigned long unused;
    unsigned long a;
    unsigned long b;
    unsigned long c;
    Control* control;
    unsigned long d;
    unsigned long e;

    S* initialize(Argument argument);
};

S* S::initialize(Argument argument)
{
    type = 0;
    if (!reinterpret_cast<bool (__cdecl *)(Argument*)>(
            &func_0060a2f0)(&argument))
    {
        volatile unsigned long* destination = &a;
        if (destination)
        {
            destination[0] = argument.a;
            destination[1] = argument.b;
            destination[2] = argument.c;
            reinterpret_cast<Control* volatile*>(destination)[3] = argument.control;
            Control* copied = argument.control;
            if (copied)
                _InterlockedIncrement(&copied->strong);
            destination[4] = argument.d;
            destination[5] = argument.e;
        }
        type = table_0080ee20;
    }
    else
    {
        type = 0;
    }

    if (argument.control)
    {
        Control* owner = argument.control;
        if (_InterlockedDecrement(&owner->strong) == 0)
        {
            owner->dispose();
            if (_InterlockedDecrement(&owner->weak) == 0)
                owner->destroy();
        }
    }
    return this;
}
