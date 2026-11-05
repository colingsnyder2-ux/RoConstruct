// from server: 24% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Arg {
    int a;
    int b;
};

struct AdornBillboarder {
    void* vptr;
    int field4;
    void invoke(Arg, Arg, Arg, Arg, Arg, Arg, Arg, Arg, Arg);
};

void AdornBillboarder::invoke(Arg a1, Arg a2, Arg a3, Arg a4, Arg a5, Arg a6, Arg a7, Arg a8, Arg a9)
{
    RefCounted* p1 = (RefCounted*)a1.a;
    RefCounted* p2 = (RefCounted*)a2.a;
    RefCounted* p3 = (RefCounted*)a3.a;
    RefCounted* p4 = (RefCounted*)a4.a;
    RefCounted* p5 = (RefCounted*)a5.a;
    RefCounted* p6 = (RefCounted*)a6.a;

    if (p1) _InterlockedExchangeAdd(&p1->refcount, 1);
    if (p2) _InterlockedExchangeAdd(&p2->refcount, 1);

    void (*fn)(void*) = *(void (**)(void*))this->vptr;
    int off = this->field4 + a3.b;
    fn((void*)off);

    if (p1) {
        if (_InterlockedExchangeAdd(&p1->refcount, -1) == 1) {
            (*(void (**)(RefCounted*))p1->vptr)(p1);
        }
    }
    if (p2) {
        if (_InterlockedExchangeAdd(&p2->refcount, -1) == 1) {
            (*(void (**)(RefCounted*))p2->vptr)(p2);
        }
    }
}
