// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Inner {
    void* vptr;
    void (__thiscall *dtor)(Inner*, int);
};

struct Holder {
    Inner* ptr;
};

extern "C" void __cdecl sub_7300F0(void*, void*, void*);
extern "C" void __cdecl sub_50BF80(void*);
extern "C" void __cdecl sub_695930(void*, void*, void*, int);

struct VCollectionService {
    void func(void* a, void* b, void* c, void* d);
};

void VCollectionService::func(void* a, void* b, void* c, void* d)
{
    char pad[0x28];
    void* local1c;
    void* local18;
    void* local14;
    void* local10;
    void* local0c;
    void* local08;
    void* local04;
    void* local00;
    (void)pad; (void)local1c; (void)local18; (void)local14;
    (void)local10; (void)local0c; (void)local08; (void)local04; (void)local00;

    unsigned char flag = *(unsigned char*)0xb96965;
    void* p = c;
    void* q = d;

    void* arr[2];
    arr[0] = p;
    arr[1] = q;

    if (q) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }

    sub_7300F0(arr, (void*)0x5055a0, 0);
    sub_50BF80(&local1c);

    sub_695930(this, a, b, 10);

    if (local1c) {
        Inner* inner = *(Inner**)local1c;
        if (inner) {
            inner->dtor(inner, 2);
        }
        local1c = 0;
    }

    if (q) {
        RefCounted* rc = (RefCounted*)q;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            rc->vptr = 0;
            ((void (__thiscall*)(void*))((void**)rc->vptr)[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(void*))((void**)rc->vptr)[2])(rc);
            }
        }
    }
    (void)flag;
}
