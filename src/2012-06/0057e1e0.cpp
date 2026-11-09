// from server: 55% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_972290(int, const char*);
extern "C" void* __cdecl sub_57e160(void*);

struct RefCounted {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

struct Result {
    void* a;
    void* b;
};

extern char g_e580b3;
extern int g_e246b4;
extern int (__cdecl *g_e5809c)(int, const char*, const char*);

struct S {
    Result* __thiscall f(Result* out);
};

Result* __thiscall S::f(Result* out) {
    Holder h;
    h.ptr = 0;
    if (g_e580b3 != 0 && g_e246b4 != 0x29a) {
        if (g_e5809c != 0) {
            if (g_e5809c(0xca, (const char*)0xb42fa8, (const char*)0xb42f90)) {
                goto skip;
            }
        }
        sub_972290((int)(unsigned char)g_e580b3, (const char*)0xb432f8);
    }
skip:
    {
        void* tmp = 0;
        sub_57e160(&tmp);
        RefCounted* p = *(RefCounted**)&tmp;
        if (p != 0) {
            out->a = (char*)p + 0x18;
        } else {
            out->a = 0;
        }
        RefCounted* q = *(RefCounted**)((char*)&tmp + 4);
        out->b = q;
        if (q != 0) {
            _InterlockedExchangeAdd(&q->refcount, 1);
        }
        RefCounted* r = *(RefCounted**)&tmp;
        if (r != 0) {
            if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
                void** vt = *(void***)r;
                ((void (__thiscall*)(RefCounted*))vt[1])(r);
                if (_InterlockedExchangeAdd(&r->weakrefcount, -1) == 1) {
                    void** vt2 = *(void***)r;
                    ((void (__thiscall*)(RefCounted*))vt2[2])(r);
                }
            }
        }
    }
    return out;
}
