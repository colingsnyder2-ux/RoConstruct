// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Inner {
    void* vptr;
    void* field4;
};

struct Outer {
    void* field0;
    void* field4;
    Inner* field8;
};

struct Str {
    void* pad[4];
};

extern "C" void __stdcall sub_77E69C(void*, void*);
extern "C" void __stdcall sub_77E6AC(void*);

void __stdcall sub_413FF0(void*, void*);
void __stdcall sub_414840(void*, void*);
void __stdcall sub_4144E0(void*);

extern "C" void __stdcall string_ctor(void*, const void*);
extern "C" void __stdcall string_dtor(void*);

void __stdcall target(Outer* out, const void* src, void* a3, void* a4, void* a5)
{
    void* localbuf[8];
    void* tmp1;
    void* tmp2;
    RefCounted* r1;
    RefCounted* r2;
    void* str1[4];
    void* str2[4];
    void* str3[4];
    void* str4[4];
    int state = 0;

    sub_77E69C(localbuf, a3);

    r1 = (RefCounted*)a4;
    r2 = (RefCounted*)a5;

    if (r1) {
        _InterlockedExchangeAdd(&r1->refcount, 1);
    }
    if (r2) {
        _InterlockedExchangeAdd(&r2->refcount, 1);
    }

    sub_413FF0(str1, localbuf);
    out->field0 = str1[0];
    out->field4 = str1[1];
    sub_414840(&out->field8, str1);

    state = 1;
    sub_4144E0(str2);

    if (r2) {
        if (_InterlockedExchangeAdd(&r2->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))((void**)r2->vptr)[1])(r2);
            if (_InterlockedExchangeAdd(&r2->weakrefcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))((void**)r2->vptr)[2])(r2);
            }
        }
    }

    if (r1) {
        if (_InterlockedExchangeAdd(&r1->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))((void**)r1->vptr)[1])(r1);
            if (_InterlockedExchangeAdd(&r1->weakrefcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))((void**)r1->vptr)[2])(r1);
            }
        }
    }

    sub_77E6AC(str3);
}
