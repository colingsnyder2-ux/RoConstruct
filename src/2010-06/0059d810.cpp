// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Obj98 {
    void* ptr;
    RefCounted* rc;
};

struct PacketReceiveJob {
    char pad0[0x4c];
    void* field4c;
    char pad50[0x48];
    void* field98;
    RefCounted* field9c;
    void* fielda0;
    RefCounted* fielda4;
    void run();
};

extern "C" void* __cdecl sub_7a79a0(unsigned int);
extern "C" void __cdecl sub_59d3c0(void*, void*);
extern "C" void __cdecl sub_59c7e0(void*);
extern "C" void __cdecl sub_59c9d0(void*, void*);
extern "C" void __cdecl sub_59ca80(void*, void*);
extern "C" void __cdecl sub_4d97c0(void*, void*);
extern "C" void __cdecl sub_59d530(void*);
extern "C" void __cdecl sub_402090(void*, void*);
extern "C" void* __cdecl sub_79b5b0();
extern "C" void __cdecl sub_79a770(void*);

void PacketReceiveJob::run() {
    void* p1 = sub_7a79a0(0x1e0);
    if (p1) {
        void* src;
        if (field4c) {
            src = (char*)field4c + 0x2c;
        } else {
            src = 0;
        }
        sub_59d3c0(&src, src);
        sub_59c7e0(p1);
    } else {
        p1 = 0;
    }
    void* tmp1;
    sub_59c9d0(&tmp1, p1);
    field98 = *(void**)tmp1;
    sub_402090(&field9c, (char*)tmp1 + 4);
    if (tmp1) {
        RefCounted* rc = (RefCounted*)tmp1;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 0) {
            ((void (__thiscall*)(void*))rc->vptr)(rc);
        }
    }
    void* p2 = sub_7a79a0(0x1e8);
    if (p2) {
        void* tmp2;
        sub_4d97c0(&tmp2, this);
        sub_59d530(p2);
    } else {
        p2 = 0;
    }
    void* tmp3;
    sub_59ca80(&tmp3, p2);
    fielda0 = *(void**)tmp3;
    sub_402090(&fielda4, (char*)tmp3 + 4);
    if (tmp3) {
        RefCounted* rc = (RefCounted*)tmp3;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 0) {
            ((void (__thiscall*)(void*))rc->vptr)(rc);
        }
    }
    {
        Obj98 o;
        o.ptr = field98;
        o.rc = field9c;
        if (o.rc) {
            _InterlockedExchangeAdd(&o.rc->refcount, 1);
        }
        void* r = sub_79b5b0();
        sub_79a770(r);
    }
    {
        Obj98 o;
        o.ptr = fielda0;
        o.rc = fielda4;
        if (o.rc) {
            _InterlockedExchangeAdd(&o.rc->refcount, 1);
        }
        void* r = sub_79b5b0();
        sub_79a770(r);
    }
}
