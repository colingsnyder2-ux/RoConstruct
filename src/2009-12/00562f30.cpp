// from server: 20% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

bool func_00759970();

struct RefCounted {
    void** vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Receiver {
    bool method(int a, int b, int c, int d, int e, int f, int g, int h);
};

bool Receiver::method(int a, int b, int c, int d, int e, int f, int g, int h)
{
    RefCounted* p;
    bool result;
    {
        result = func_00759970();
        if (result)
            return false;
        p = (RefCounted*)h;
        if (p)
            _InterlockedExchangeAdd(&p->ref1, 1);
        ((void(*)(Receiver*, int, int, int, int, int, int, int, int))0x562820)(this, a, b, c, d, e, f, g, h);
    }
    if (p)
    {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1)
        {
            ((void(*)(RefCounted*))p->vptr[1])(p);
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1)
                ((void(*)(RefCounted*))p->vptr[2])(p);
        }
    }
    return true;
}
