// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sprintf(char*, const char*, ...);

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Obj {
    void* vptr;
};

struct Holder {
    Obj* ptr;
};

struct Inner {
    char pad[0x78];
    void* field78;
};

struct CRobloxDoc {
    char pad[0x78];
    void* field78;
    void func1(Holder* out);
    void func2(Holder* out);
    void method(int arg);
};

extern "C" void __cdecl sub_403830(Holder* out);
extern "C" void __cdecl sub_403800(Holder* out);
extern "C" void __cdecl sub_40d550(void* p);
extern "C" void __cdecl sub_5579d0(void* p);
extern "C" void __cdecl sub_5595a0(void* p);
extern "C" void __cdecl sub_630a1e(void);

extern "C" void* __cdecl sub_77e968(char* buf, const char* fmt, ...);

void CRobloxDoc::method(int arg) {
    Holder h1;
    Holder h2;
    char buf[32];
    bool flag;

    sub_403830(&h1);
    flag = (h1.ptr != 0);

    if (h1.ptr) {
        RefCounted* rc = (RefCounted*)h1.ptr;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            void** vt = (void**)rc->vptr;
            ((void (__thiscall*)(void*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                void** vt2 = (void**)rc->vptr;
                ((void (__thiscall*)(void*))vt2[2])(rc);
            }
        }
    }

    if (flag) {
        sub_403800(&h2);
        Holder h3;
        h3.ptr = h2.ptr;
        if (h3.ptr) {
            RefCounted* rc = (RefCounted*)h3.ptr;
            _InterlockedExchangeAdd(&rc->refcount, 1);
        }
        sub_40d550(&h3);
        if (h2.ptr) {
            RefCounted* rc = (RefCounted*)h2.ptr;
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
                void** vt = (void**)rc->vptr;
                ((void (__thiscall*)(void*))vt[1])(rc);
                if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                    void** vt2 = (void**)rc->vptr;
                    ((void (__thiscall*)(void*))vt2[2])(rc);
                }
            }
        }
        sub_403830(&h3);
        sub_5579d0(h3.ptr);
        double d = 0.0;
        sub_77e968(buf, "%.4g", d);
        if (h3.ptr) {
            RefCounted* rc = (RefCounted*)h3.ptr;
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
                void** vt = (void**)rc->vptr;
                ((void (__thiscall*)(void*))vt[1])(rc);
                if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                    void** vt2 = (void**)rc->vptr;
                    ((void (__thiscall*)(void*))vt2[2])(rc);
                }
            }
        }
        sub_5595a0(&h2);
        void** vt = (void**)((Obj*)arg)->vptr;
        ((void (__thiscall*)(void*, void*))vt[3])((void*)arg, buf);
    }
}
