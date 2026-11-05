// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    void Release();
};

struct Obj98 {
    char pad[0x98];
    int field98;
};

struct Inner {
    void* ptr;
};

struct Outer {
    char pad0[0x9c];
    Inner* inner;
};

extern "C" void __stdcall sub_00476b90(void*, void*);
extern "C" void __stdcall sub_0066ff30(void*);
extern "C" void* __stdcall sub_00402120(void*);
extern "C" void* __stdcall sub_00427b80(void*);
extern "C" void __stdcall sub_0066aa30(void*);

struct CRobloxDoc {
    char pad[0x9c];
    Inner* inner;
    void func(int);
};

void CRobloxDoc::func(int arg)
{
    void* local8 = 0;
    void* localC = 0;
    void* local10 = 0;
    void* local14 = 0;

    sub_00476b90(this->inner, &local8);
    sub_0066ff30(&local8);

    void* p = sub_00402120(&localC);
    void* q = *(void**)p;
    void* r = 0;
    if (q != 0) {
        r = sub_00427b80(q);
    }

    void* s = local10;
    if (s != 0) {
        RefCounted* rc = (RefCounted*)s;
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            void** vt = *(void***)rc;
            ((void (__thiscall*)(void*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                void** vt2 = *(void***)rc;
                ((void (__thiscall*)(void*))vt2[2])(rc);
            }
        }
    }

    int flag = 0;
    if (r != 0) {
        if (((Obj98*)r)->field98 != 0) {
            flag = 1;
        }
    }

    void** vt3 = *(void***)this;
    ((void (__thiscall*)(void*, int))vt3[0])(this, flag);

    sub_0066aa30(&local8);
}
