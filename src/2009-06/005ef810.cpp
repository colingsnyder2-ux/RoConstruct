// from server: 40% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Outer {
    char pad0[4];
    Inner* ptr;
};

struct S {
    void* field0;
    void* field4;
    S* f(void* a, void* b);
};

void __stdcall helper(void* a, void* b);

S* S::f(void* a, void* b) {
    this->field0 = a;
    helper(&this->field4, a);
    if (a == 0) {
        return this;
    }
    Outer* o = (Outer*)((char*)a + 0x24);
    if (o != 0) {
        *(void**)o = a;
        Inner* old = (Inner*)this->field4;
        if (old != o->ptr) {
            if (old != 0) {
                _InterlockedExchangeAdd(&old->refcount, 1);
            }
            Inner* cur = (Inner*)o->ptr;
            if (cur != 0) {
                if (_InterlockedExchangeAdd(&cur->refcount, -1) == 1) {
                    void** vt = *(void***)cur;
                    void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                    fn(cur);
                }
            }
            o->ptr = old;
        }
    }
    return this;
}
