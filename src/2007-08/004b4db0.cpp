// from server: 33% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Arg1 {
    void* p;
};

struct Arg2 {
    void* p;
};

struct Arg3 {
    void* p;
};

struct Arg4 {
    void* p;
};

struct Helper1 {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
};

struct Helper2 {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
};

extern "C" void __cdecl func_417860(void*, void*);
extern "C" void __cdecl func_40cc20(void*, void*, void*);
extern "C" void __cdecl func_4b3a60(void*, void*);
extern "C" void __cdecl func_4ae3d0(void*, void*, void*, void*);
extern "C" void __cdecl func_49a230(void*);

struct VReplicatorSignalDesc {
    void* method(Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4);
};

void* VReplicatorSignalDesc::method(Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4) {
    Helper1 h1;
    Helper2 h2;
    void* result;
    RefCounted* rc;
    
    h1.field0 = 0;
    h1.field4 = a1.p;
    func_417860(&h1, a1.p);
    func_40cc20(&h1, a1.p, a1.p);
    func_4b3a60(&h2, &h1);
    func_4ae3d0(a3.p, a2.p, &h2, a4.p);
    func_49a230(&h1);
    
    rc = (RefCounted*)h1.field4;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vtbl = (void**)rc->vptr;
            void (*dtor)(void*) = (void (*)(void*))vtbl[1];
            dtor(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void (*dtor2)(void*) = (void (*)(void*))vtbl[2];
                dtor2(rc);
            }
        }
    }
    
    return a2.p;
}
