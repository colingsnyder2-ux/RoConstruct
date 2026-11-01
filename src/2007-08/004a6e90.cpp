// from server: 69% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    volatile long refCount;
    volatile long weakRefCount;
};

struct S {
    void* field0;
    void* field4;
    RefCounted* field8;
    S* construct(void* a, void* b, RefCounted* c);
};

S* S::construct(void* a, void* b, RefCounted* c)
{
    this->field0 = a;
    this->field4 = b;
    this->field8 = c;
    if (c) {
        if (_InterlockedExchangeAdd(&c->refCount, 1) == 0) {
            void** vt = c->vptr;
            void (*fn)(RefCounted*) = (void (*)(RefCounted*))vt[1];
            fn(c);
        }
        if (_InterlockedExchangeAdd(&c->weakRefCount, -1) == 1) {
            void** vt = c->vptr;
            void (*fn)(RefCounted*) = (void (*)(RefCounted*))vt[2];
            fn(c);
        }
    }
    return this;
}
