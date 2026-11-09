// from server: 64% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

struct Inner {
    char pad[0x18];
    RefCounted* obj;
};

struct Outer {
    Inner* inner;
    RefCounted* obj;
};

extern "C" Outer* __cdecl sub_656B30(Inner** out);

struct Creator {
    Holder* __thiscall create(Holder* result);
};

Holder* Creator::create(Holder* result) {
    Inner* tmp = 0;
    Outer* o = sub_656B30(&tmp);
    RefCounted* p = (RefCounted*)o->inner;
    if (p) {
        p = (RefCounted*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    result->ptr = p;
    RefCounted* q = o->obj;
    result->ptr2 = q;
    if (q) {
        _InterlockedExchangeAdd(&q->refcount, 1);
    }
    RefCounted* old = (RefCounted*)tmp;
    if (old) {
        if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
            void** vt = *(void***)old;
            ((void (__thiscall*)(RefCounted*))vt[1])(old);
            if (_InterlockedExchangeAdd((volatile long*)((char*)old + 8), -1) == 1) {
                void** vt2 = *(void***)old;
                ((void (__thiscall*)(RefCounted*))vt2[2])(old);
            }
        }
    }
    return result;
}
