// from server: 59% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern "C" void* __cdecl sub_4141e0(void*);

struct RefCounted {
    void* vptr;
    volatile long refcount;
};

struct Holder {
    void* ptr;
    RefCounted* obj;
};

struct Result {
    void* ptr;
    RefCounted* obj;
};

extern unsigned char byte_E580B3;
extern int dword_E1653C;
extern void* (__cdecl *dword_E5809C)(const char*, const char*, int);

Result* __cdecl sub_4148C0(Result* out);

Result* __cdecl sub_4148C0(Result* out)
{
    Holder h;
    h.ptr = 0;
    h.obj = 0;

    if (byte_E580B3 != 0 && dword_E1653C != 0x29a) {
        if (dword_E5809C != 0) {
            if (dword_E5809C("wasConstructed()",
                             "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h",
                             0xca)) {
                goto skip;
            }
        }
        sub_972290(byte_E580B3,
                   "wasConstructed() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h line: 202");
    }
skip:
    sub_4141e0(&h);

    RefCounted* obj = h.obj;
    if (obj != 0) {
        obj = (RefCounted*)((char*)obj + 0x18);
    } else {
        obj = 0;
    }

    out->ptr = obj;
    out->obj = h.obj;
    if (h.obj != 0) {
        _InterlockedExchangeAdd(&h.obj->refcount, 1);
    }

    RefCounted* old = h.obj;
    if (old != 0) {
        if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
            void (*f1)(RefCounted*) = *(void (**)(RefCounted*))((char*)old->vptr + 4);
            f1(old);
            if (_InterlockedExchangeAdd((volatile long*)((char*)old + 8), -1) == 1) {
                void (*f2)(RefCounted*) = *(void (**)(RefCounted*))((char*)old->vptr + 8);
                f2(old);
            }
        }
    }

    return out;
}
