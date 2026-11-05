// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Inner {
    void* p;
};

struct Track {
    char pad0[0x80];
    Inner inner80;
    char pad8c[0x88 - 0x84];
    Inner inner88;

    double getValue();
};

extern "C" void __stdcall sub_00439330(void*, void*);
extern "C" void __stdcall sub_005728d0(void*);
extern "C" double __stdcall sub_008fe610(void*);

double Track::getValue()
{
    Inner tmp;
    sub_00439330(&tmp, &inner88);
    if (tmp.p != 0) {
        double result = sub_008fe610(tmp.p);
        RefCounted* rc = (RefCounted*)tmp.p;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))rc->vptr[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))rc->vptr[2])(rc);
            }
        }
        return result;
    }
    RefCounted* rc = (RefCounted*)tmp.p;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))rc->vptr[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))rc->vptr[2])(rc);
            }
        }
    }
    sub_005728d0(&inner80);
    return 0.0;
}
