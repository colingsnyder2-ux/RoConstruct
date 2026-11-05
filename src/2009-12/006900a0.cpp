// from server: 43% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" int __cdecl sub_68F7D0(void*, const char*, int, int);
extern "C" void __cdecl sub_45FBE0(void*, void*);
extern "C" void __cdecl sub_854A90(void*, void*, void*);
extern "C" void __cdecl sub_41C010(void*);
extern "C" void __cdecl sub_708980(void*, void*);
extern "C" void __cdecl sub_41B230(void*);
extern "C" void __cdecl sub_41AF50(void*);

struct RefCounted {
    void* vptr;
    long refcount;
    long weakref;
};

struct Holder {
    void* ptr;
    void* ctrl;
};

struct S {
    void* method(char* out, int a, int b);
};

void* S::method(char* out, int a, int b)
{
    void* obj = sub_7F3860(0x48);
    RefCounted* rc = 0;
    if (obj != 0) {
        rc = (RefCounted*)sub_68F7D0(obj, (const char*)a, b, 0x7fffffff);
    }
    Holder h;
    h.ptr = 0;
    h.ctrl = 0;
    sub_45FBE0(&h, rc);
    sub_854A90(&h, 0, 0);
    sub_41C010(this);
    sub_708980(this, &h);
    void* (__stdcall *fn1)(void*) = *(void* (__stdcall**)(void*))0x98b20c;
    fn1((void*)0xb90258);
    Holder h2;
    h2.ptr = h.ptr;
    h2.ctrl = h.ctrl;
    if (h2.ctrl != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)h2.ctrl + 4), 1);
    }
    sub_41B230(&h2);
    void* (__stdcall *fn2)(void*) = *(void* (__stdcall**)(void*))0x98b20c;
    fn2((void*)0xb7a220);
    Holder* src = (Holder*)0;
    (void)src;
    *(void**)out = h2.ptr;
    *(void**)(out + 4) = h2.ctrl;
    if (h2.ctrl != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)h2.ctrl + 8), 1);
    }
    sub_41AF50(&h);
    if (rc != 0) {
        if (_InterlockedExchangeAdd((volatile long*)&rc->refcount, -1) == 1) {
            rc->vptr;
            ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[1])(rc);
            if (_InterlockedExchangeAdd((volatile long*)&rc->weakref, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    return this;
}
