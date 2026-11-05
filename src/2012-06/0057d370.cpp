// from server: 43% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_972290(int, const char*);
extern "C" void* __cdecl sub_57d2f0(void*);

struct RefCounted {
    void** vptr;
    volatile long refcount;
    volatile long weakref;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

struct Creator {
    Holder* __stdcall create(Holder* out);
};

Holder* __stdcall sub_57d2f0(Holder* out);

Creator* __stdcall sub_57d2f0_creator(Holder* out);

Holder* __stdcall Creator_create(Holder* out);

extern char byte_e580b3;
extern int dword_e246a8;
extern int dword_e5809c;
extern char str_b42f90[];
extern char str_b42fa8[];
extern char str_b432f8[];

Holder* __stdcall sub_57d2f0(Holder* out);

Holder* __stdcall Creator::create(Holder* out)
{
    Holder* result;
    RefCounted* p;
    RefCounted* q;
    int old;

    if (byte_e580b3 != 0 && dword_e246a8 != 0x29a) {
        if (dword_e5809c != 0) {
            if (((char (__stdcall*)(int, char*, char*))dword_e5809c)(0xca, str_b42fa8, str_b42f90) != 0) {
                goto skip;
            }
        }
        sub_972290((int)byte_e580b3, str_b432f8);
    }
skip:
    result = sub_57d2f0(out);
    p = result->ptr;
    if (p != 0) {
        p = (RefCounted*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    out->ptr = p;
    q = result->ptr2;
    out->ptr2 = q;
    if (q != 0) {
        _InterlockedExchangeAdd(&q->refcount, 1);
    }
    if (p != 0) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))p->vptr[1])(p);
            if (_InterlockedExchangeAdd(&p->weakref, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))p->vptr[2])(p);
            }
        }
    }
    return out;
}
