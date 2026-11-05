// from server: 33% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Inner {
    void* vptr;
    RefCounted* ptr;
};

struct Outer {
    char pad[0x78];
    void* field78;

    void method(int arg);
};

struct Holder {
    void* vptr;
    RefCounted* ptr;
};

struct Arg {
    void* vptr;
    RefCounted* ptr;
};

extern "C" void __stdcall sub_403800(void*, void*);
extern "C" void __stdcall sub_403830(void*, void*);
extern "C" void __stdcall sub_40D550(void*);
extern "C" void __stdcall sub_40E750(void*);
extern "C" int __stdcall sub_491980(void*);
extern "C" void __stdcall sub_5595A0(void*);

void Outer::method(int arg)
{
    Inner inner;
    sub_403800(field78, &inner);
    Holder holder;
    holder.vptr = inner.vptr;
    holder.ptr = inner.ptr;
    if (holder.ptr) {
        _InterlockedExchangeAdd(&holder.ptr->refcount, 1);
    }
    sub_40D550(&holder);
    if (inner.ptr) {
        if (_InterlockedExchangeAdd(&inner.ptr->refcount, -1) == 1) {
            void (__stdcall *f)(void*) = *(void (__stdcall **)(void*))((char*)inner.ptr->vptr + 4);
            f(inner.ptr);
            if (_InterlockedExchangeAdd(&inner.ptr->weakrefcount, -1) == 1) {
                void (__stdcall *g)(void*) = *(void (__stdcall **)(void*))((char*)inner.ptr->vptr + 8);
                g(inner.ptr);
            }
        }
    }
    Arg arg2;
    sub_403830(this, &arg2);
    void* p = *(void**)arg2.vptr;
    void* q = *(void**)holder.ptr;
    sub_40E750(p);
    int r = sub_491980(p);
    int flag = (r == 0) ? 1 : 0;
    ((void (__stdcall *)(int))q)(flag);
    if (arg2.ptr) {
        if (_InterlockedExchangeAdd(&arg2.ptr->refcount, -1) == 1) {
            void (__stdcall *f2)(void*) = *(void (__stdcall **)(void*))((char*)arg2.ptr->vptr + 4);
            f2(arg2.ptr);
            if (_InterlockedExchangeAdd(&arg2.ptr->weakrefcount, -1) == 1) {
                void (__stdcall *g2)(void*) = *(void (__stdcall **)(void*))((char*)arg2.ptr->vptr + 8);
                g2(arg2.ptr);
            }
        }
    }
    sub_5595A0(&arg2);
}
