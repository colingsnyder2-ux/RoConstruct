// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void* __cdecl sub_68F8C0(void*, const void*, unsigned int);
extern "C" void __cdecl sub_4C0520(void*, void*);
extern "C" void __cdecl sub_854A90(void*, void*, void*);
extern "C" void __cdecl sub_41C010(void*);
extern "C" void __cdecl sub_708980(void*, void*);
extern "C" void __cdecl sub_41B230(void*);
extern "C" void __cdecl sub_41AF50(void*);

extern "C" void* (__stdcall *off_98B20C)(void*);

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Holder {
    void* ptr;
    RefCounted* obj;
};

struct S {
    void* f(void* a, void* b, void* c);
};

void* S::f(void* a, void* b, void* c)
{
    void* result;
    void* tmp;
    Holder h;
    Holder h2;
    RefCounted* rc;
    void* p;

    result = 0;
    tmp = sub_7F3860(0x48);
    if (tmp != 0) {
        result = sub_68F8C0(tmp, b, 0x7fffffff);
    }

    h.ptr = result;
    h.obj = 0;
    sub_4C0520(&h, result);
    sub_854A90(&h, result, result);

    sub_41C010(this);
    sub_708980(this, &h);

    off_98B20C((void*)0xB90258);

    h2.ptr = h.ptr;
    h2.obj = h.obj;
    if (h2.obj != 0) {
        _InterlockedExchangeAdd(&h2.obj->refcount, 1);
    }

    sub_41B230(&h2);
    p = (void*)0;
    off_98B20C((void*)0xB7A220);

    *(void**)c = *(void**)p;
    *(void**)((char*)c + 4) = *(void**)((char*)p + 4);
    rc = *(RefCounted**)((char*)p + 4);
    if (rc != 0) {
        _InterlockedExchangeAdd(&rc->refcount, 1);
    }

    sub_41AF50(&h);

    if (h.obj != 0) {
        if (_InterlockedExchangeAdd(&h.obj->refcount, -1) == 1) {
            h.obj->vptr;
            ((void (__thiscall*)(RefCounted*))(*(void***)h.obj)[1])(h.obj);
            if (_InterlockedExchangeAdd(&h.obj->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))(*(void***)h.obj)[2])(h.obj);
            }
        }
    }

    return c;
}
