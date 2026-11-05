// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vt;
    volatile long ref1;
    volatile long ref2;
};

struct Outer {
    void* vt;
    volatile long ref;
};

struct S {
    char pad[8];
    void* field;
    int method(int, int, int, int, int);
};

extern "C" void __stdcall sub_4f3f80();

int S::method(int a, int b, int c, int d, int e)
{
    Inner* p = (Inner*)d;
    if (p)
        _InterlockedExchangeAdd(&p->ref1, 1);
    sub_4f3f80();
    Inner* q = (Inner*)d;
    if (q)
    {
        if (_InterlockedExchangeAdd(&q->ref1, -1) == 1)
        {
            void** vt = *(void***)q;
            ((void (__stdcall*)(Inner*))vt[1])(q);
            if (_InterlockedExchangeAdd(&q->ref2, -1) == 1)
            {
                void** vt2 = *(void***)q;
                ((void (__stdcall*)(Inner*))vt2[2])(q);
            }
        }
    }
    return (int)this;
}
