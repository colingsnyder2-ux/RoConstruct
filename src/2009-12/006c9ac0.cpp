// from server: 12% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_6c86f0();
extern "C" void __cdecl sub_6c9380();
extern "C" void __cdecl sub_6c9a40();

extern unsigned char byte_B925E5;
extern unsigned char byte_B92569;

struct RefCounted {
    void* vptr;
    long refcount;
    long refcount2;
};

struct VExplosionEventDesc {
    void construct(int a, int b, int c, int d);
};

void VExplosionEventDesc::construct(int a, int b, int c, int d)
{
    void* saved;
    char buf[0x28];
    RefCounted* rc;
    int local;

    local = 0;
    saved = 0;

    sub_6c86f0();
    sub_6c9380();
    sub_6c9a40();

    rc = 0;
    if (rc) {
        if (rc->vptr) {
            ((void (__stdcall*)(int, void*, void*))rc->vptr)(2, &local, &local);
        }
        rc = 0;
    }

    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(void))rc->vptr)();
            if (_InterlockedExchangeAdd(&rc->refcount2, -1) == 1) {
                ((void (__stdcall*)(void))rc->vptr)();
            }
        }
    }
}
