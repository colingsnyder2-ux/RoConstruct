// from server: 46% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_78A660(int, int, int);

struct RefCounted {
    void** vptr;
    long refcount;
};

struct Holder {
    char pad[8];
    RefCounted* ptr;
};

int __cdecl sub_6A37A0(int a)
{
    Holder* h = (Holder*)sub_78A660(*(int*)0x00B62B80, 1, a);
    RefCounted* p = *(RefCounted**)((char*)h + 8);
    if (p != 0) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            void** vt = p->vptr;
            ((void (__thiscall*)(RefCounted*))vt[2])(p);
        }
    }
    return 0;
}
