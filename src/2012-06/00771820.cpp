// from server: 55% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_972290(int, const char*);
extern "C" void* __cdecl sub_7717A0(void*);

struct RefCounted {
    void** vptr;
    long refcount;
    long weakref;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

struct Result {
    RefCounted* a;
    RefCounted* b;
};

struct Factory {
    Result* __thiscall create(Result* out);
};

Result* __thiscall Factory::create(Result* out) {
    Holder h;
    h.ptr = 0;
    h.ptr2 = 0;

    if (*(char*)0xe580b3 != 0) {
        if (*(int*)0xe3793c != 0x29a) {
            void* fn = *(void**)0xe5809c;
            if (fn != 0) {
                char ok = ((char (__stdcall*)(int, const char*, const char*))fn)(0xca, (const char*)0xb42fa8, (const char*)0xb42f90);
                if (ok == 0) {
                    sub_972290(*(unsigned char*)0xe580b3, (const char*)0xb432f8);
                }
            } else {
                sub_972290(*(unsigned char*)0xe580b3, (const char*)0xb432f8);
            }
        }
    }

    Holder* r = (Holder*)sub_7717A0(&h);
    RefCounted* p = r->ptr;
    if (p != 0) {
        p = (RefCounted*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    out->a = p;
    RefCounted* q = r->ptr2;
    out->b = q;
    if (q != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }

    RefCounted* old = h.ptr;
    if (old != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)old + 4), -1) == 1) {
            ((void (__thiscall*)(RefCounted*))old->vptr[1])(old);
            if (_InterlockedExchangeAdd((volatile long*)((char*)old + 8), -1) == 1) {
                ((void (__thiscall*)(RefCounted*))old->vptr[2])(old);
            }
        }
    }

    return out;
}
