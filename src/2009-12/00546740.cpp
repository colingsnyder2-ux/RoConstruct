// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vtbl;
    volatile long ref1;
    volatile long ref2;
};

struct Outer {
    void* field0;
    Inner* inner;
    void method2();
    void method(int, int, int, int);
};

void Outer::method(int a, int b, int c, int d)
{
    Inner* p = inner;
    if (p)
        _InterlockedExchangeAdd(&p->ref1, 1);

    struct Local {
        int x, y, z;
    } loc;
    loc.x = a;
    loc.y = b;
    loc.z = c;

    Inner* q = inner;
    if (q)
        _InterlockedExchangeAdd(&q->ref1, 1);

    method2();

    if (q) {
        if (_InterlockedExchangeAdd(&q->ref1, -1) == 1) {
            q->vtbl;
            ((void (__thiscall*)(Inner*))((void**)q->vtbl)[1])(q);
        }
        if (_InterlockedExchangeAdd(&q->ref2, -1) == 1) {
            ((void (__thiscall*)(Inner*))((void**)q->vtbl)[2])(q);
        }
    }
}
