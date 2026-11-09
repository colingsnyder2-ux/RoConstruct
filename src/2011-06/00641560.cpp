// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_5ba180();
extern "C" void __cdecl sub_4adcb0(void*, void*);
extern "C" void* __cdecl sub_721520(void*, void*);

struct RefCounted {
    void* vfptr;
    long refcount;
    long weakrefcount;
};

struct VPlayer {
    char pad[0x20];
    void* field20;
};

struct RefPropDescriptor {
    void* vfptr;
    char pad[0x1c];
    void* field20;
    void* assign(void* a, void* b);
};

void* RefPropDescriptor::assign(void* a, void* b) {
    void* src = *(void**)((char*)field20 + 0);
    void* (*fn)(void*) = *(void* (**)(void*))((char*)src + 8);
    void* result = fn(a);
    void* tmp;
    sub_721520(&tmp, result);
    void* obj = *(void**)tmp;
    void* p1;
    if (obj) {
        p1 = (char*)obj + 0x1c;
    } else {
        p1 = 0;
    }
    void* p2 = *(void**)((char*)tmp + 4);
    if (p2) {
        _InterlockedExchangeAdd((volatile long*)((char*)p2 + 4), 1);
    }
    if (b) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
            void* (*d)(void*) = *(void* (**)(void*))((char*)*(void**)b + 4);
            d(b);
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 8), -1) == 1) {
                void* (*d2)(void*) = *(void* (**)(void*))((char*)*(void**)b + 8);
                d2(b);
            }
        }
    }
    _InterlockedExchangeAdd((volatile long*)0xcca710, 1);
    void* r = sub_5ba180();
    *(void**)a = r;
    sub_4adcb0((char*)a + 4, &p1);
    if (p2) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p2 + 4), -1) == 1) {
            void* (*d)(void*) = *(void* (**)(void*))((char*)*(void**)p2 + 4);
            d(p2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p2 + 8), -1) == 1) {
                void* (*d2)(void*) = *(void* (**)(void*))((char*)*(void**)p2 + 8);
                d2(p2);
            }
        }
    }
    return a;
}
