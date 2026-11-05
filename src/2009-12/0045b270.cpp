// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Inner {
    void* vptr;
    void Release();
};

struct Obj {
    char pad[0x9c];
    void* field9c;
    void Method();
};

extern "C" void __stdcall sub_476b90(void*, void*);
extern "C" void __stdcall sub_66ff30(void*);
extern "C" void* __stdcall sub_402120(void*, void*);
extern "C" void __stdcall sub_458ea0(void*);
extern "C" void __stdcall sub_63c310(void*, int);
extern "C" void __stdcall sub_66aa30(void*);

void Obj::Method()
{
    void* local1 = 0;
    void* local2 = 0;
    void* local3 = 0;
    void* tmp = 0;

    sub_476b90(field9c, &tmp);
    sub_66ff30(&local1);

    void* p = sub_402120(this, &local2);
    void* q = *(void**)p;
    if (q != 0) {
        sub_458ea0(q);
    } else {
        q = 0;
    }
    sub_63c310(q, 2);

    RefCounted* rc = (RefCounted*)local1;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            void** vt = (void**)rc->vptr;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                void (*fn2)(void*) = (void (*)(void*))vt[2];
                fn2(rc);
            }
        }
    }

    sub_66aa30(&local3);
}
