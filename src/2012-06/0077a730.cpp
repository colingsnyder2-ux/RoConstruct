// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_00972290(int, const char*);
extern "C" void* __cdecl func_0077a6b0(void*);

struct Obj {
    void* vptr;
    long refcount;
};

struct Holder {
    Obj* f_0;
    Obj* f_4;
};

struct Result {
    Obj* f_0;
    Obj* f_4;
};

extern char g_e580b3;
extern int g_e379a8;
extern void* g_e5809c;

Result* __stdcall func_0077a730(Result* out) {
    if (g_e580b3 != 0 && g_e379a8 != 0x29a) {
        if (g_e5809c != 0) {
            typedef char (__cdecl *fn_t)(int, const char*, const char*);
            fn_t fn = (fn_t)g_e5809c;
            if (fn(0xca, (const char*)0xb42fa8, (const char*)0xb42f90)) {
                goto skip;
            }
        }
        func_00972290((int)(unsigned char)g_e580b3, (const char*)0xb432f8);
    }
skip:
    {
        Holder h;
        h.f_0 = 0;
        h.f_4 = 0;
        func_0077a6b0(&h);
        Obj* p = h.f_0;
        if (p != 0) {
            out->f_0 = (Obj*)((char*)p + 0x18);
        } else {
            out->f_0 = 0;
        }
        out->f_4 = h.f_4;
        if (h.f_4 != 0) {
            _InterlockedExchangeAdd(&h.f_4->refcount, 1);
        }
        Obj* s = h.f_0;
        if (s != 0) {
            if (_InterlockedExchangeAdd(&s->refcount, -1) == 1) {
                typedef void (__thiscall *dtor_t)(Obj*);
                dtor_t d = *(dtor_t*)(*(void**)s);
                d(s);
                if (_InterlockedExchangeAdd((volatile long*)((char*)s + 8), -1) == 1) {
                    typedef void (__thiscall *dtor2_t)(Obj*);
                    dtor2_t d2 = *(dtor2_t*)((char*)(*(void**)s) + 8);
                    d2(s);
                }
            }
        }
    }
    return out;
}
