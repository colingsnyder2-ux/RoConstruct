// from server: 17% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_004545b0();

struct RefCounted {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Obj {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Holder {
    void* ptr;
    void* ctrl;
};

struct S {
    char pad0[0x14];
    Holder h;
    char pad1[0x10];
    void* result;
    void method(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j);
};

void S::method(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j)
{
    void* p = operator_new(0x48);
    void* obj = 0;
    if (p) {
        obj = p;
    }
    void* tmp = 0;
    if (obj) {
        tmp = obj;
    }
    Holder local;
    local.ptr = 0;
    local.ctrl = 0;
    func_004545b0();
    ((void(__thiscall*)(void*))0x41fbe0)(this);
    ((void(__thiscall*)(void*, void*))0x64d9a0)(this, &local);
    void* (__stdcall* f1)(void*) = (void* (__stdcall*)(void*))0x9ea380;
    f1((void*)0xc188b4);
    Holder h2;
    h2.ptr = local.ptr;
    h2.ctrl = local.ctrl;
    if (h2.ctrl) {
        _InterlockedExchangeAdd((volatile long*)((char*)h2.ctrl + 4), 1);
    }
    ((void(__thiscall*)(void*))0x41b220)(&h2);
    f1((void*)0xc007a8);
    void* r = this->result;
    *(void**)r = h2.ptr;
    *(void**)((char*)r + 4) = h2.ctrl;
    if (h2.ctrl) {
        _InterlockedExchangeAdd((volatile long*)((char*)h2.ctrl + 8), 1);
    }
    ((void(__thiscall*)(void*))0x41afe0)(&h2);
    if (local.ctrl) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local.ctrl + 4), -1) == 1) {
            ((void(__thiscall*)(void*))((void**)local.ctrl)[1])(local.ctrl);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local.ctrl + 8), -1) == 1) {
                ((void(__thiscall*)(void*))((void**)local.ctrl)[2])(local.ctrl);
            }
        }
    }
    if (obj) {
        void* v = *(void**)obj;
        if (v) {
            ((void(__thiscall*)(void*, int, void*))v)(obj, 2, &local);
        }
    }
}
