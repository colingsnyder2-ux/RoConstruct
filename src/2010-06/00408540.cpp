// from server: 44% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refCount;
    long weakCount;
    virtual void destroy();
    virtual void deleteThis();
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

struct Factory {
    Holder* getHolder();
};

struct Creator {
    Holder* create(Holder* out);
};

Holder* Factory::getHolder()
{
    return 0;
}

Holder* Creator::create(Holder* out)
{
    Holder* src = ((Factory*)0)->getHolder();
    RefCounted* p = src->ptr;
    if (p) {
        p = (RefCounted*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    out->ptr = p;
    RefCounted* q = src->ptr2;
    out->ptr2 = q;
    if (q) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }
    RefCounted* old = src->ptr;
    if (old) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)old + 4), -1) == 1) {
            old->destroy();
            if (_InterlockedExchangeAdd((volatile long*)((char*)old + 8), -1) == 1) {
                old->deleteThis();
            }
        }
    }
    return out;
}
