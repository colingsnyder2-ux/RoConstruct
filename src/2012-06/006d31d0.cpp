// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl free(void*);
extern "C" void __cdecl func_0040c750(void*);

struct Inner {
    void** vptr;
    long refcount;
    long weakref;
};

struct Outer {
    Inner* ptr;
    Outer* assign(Outer* other);
};

Outer* Outer::assign(Outer* other)
{
    Inner* src = other->ptr;
    if (src != 0) {
        func_0040c750((char*)src + 5);
    }
    Inner* old = this->ptr;
    this->ptr = src;
    if (old != 0) {
        char* p = (char*)old + 5;
        Inner* base;
        if (p != 0) {
            base = (Inner*)(p - 5);
        } else {
            base = 0;
        }
        volatile long* rc = (volatile long*)((char*)base - 8);
        if (_InterlockedExchangeAdd(rc, -1) == 1) {
            void** vt = *(void***)base;
            void (*fn)(void*) = (void (*)(void*))vt[0];
            fn(0);
            volatile long* wrc = (volatile long*)((char*)base - 4);
            if (_InterlockedExchangeAdd(wrc, -1) == 1) {
                free((void*)base);
            }
        }
    }
    return this;
}
