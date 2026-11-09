// from server: 24% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_7062B0(int, int, int, int, int, int, int);
extern "C" void __cdecl sub_743080(int);
extern "C" void __cdecl sub_745610(int, int, int, int);

struct VRefCounted {
    void* vptr;
    volatile long refcount;
    volatile long refcount2;
};

struct VAnimationTrackState {
    int method(int, int, int, int);
};

int VAnimationTrackState::method(int a, int b, int c, int d)
{
    int local14 = 0;
    int local1c = 0;
    int local28 = 0;
    int local2c = 0;
    int local30 = 0;
    int local34 = 0;
    int local38 = 0;
    int local3c = 0;
    int local40 = 0;
    int local44 = 0;
    int local48 = 0;
    int local4c = 0;
    int local50 = 0;
    int local54 = 0;
    int local58 = 0;
    int local5c = 0;
    int local60 = 0;

    unsigned char g1 = *(unsigned char*)0xcd4fda;
    unsigned char g2 = *(unsigned char*)0xcd4fde;

    local60 = 1;

    VRefCounted* p = (VRefCounted*)a;
    if (p != 0) {
        _InterlockedExchangeAdd(&p->refcount, 1);
    }

    sub_7062B0(0, 0x741d90, (int)&local1c, g2, g1, b, c);

    sub_743080((int)&local28);

    local3c = 2;

    sub_745610((int)this, d, local48, (int)&local14);

    local14 = 1;
    local3c = 1;

    int* q = (int*)local14;
    if (q != 0) {
        int fn = *q;
        if (fn != 0) {
            ((void (__thiscall*)(void*, int, void*))fn)(q, 2, &local1c);
        }
        local14 = 0;
    }

    local3c = 0;

    VRefCounted* r = (VRefCounted*)local50;
    if (r != 0) {
        if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
            ((void (__thiscall*)(void*))r->vptr)(r);
            if (_InterlockedExchangeAdd(&r->refcount2, -1) == 1) {
                ((void (__thiscall*)(void*))r->vptr)(r);
            }
        }
    }

    return (int)this;
}
