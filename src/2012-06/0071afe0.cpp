// from server: 31% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall G1_func_00b22644();
extern "C" void __stdcall G1_func_00b2263c();

struct G1_String {
    void ctor(const G1_String&);
    void dtor();
};

struct G1_RefCounted {
    long refCount;
};

struct G1_PropDesc {
    void* vptr;
    G1_String str1;
    G1_String str2;
    G1_RefCounted* ptr1;
    G1_RefCounted* ptr2;
};

struct G1_Target {
    void func_0071a850();
    void* func_0071afe0(G1_PropDesc* src, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

void* G1_Target::func_0071afe0(G1_PropDesc* src, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    G1_PropDesc local;
    local.vptr = 0;
    local.str1.ctor(src->str1);
    local.str2.ctor(src->str2);
    local.ptr1 = src->ptr1;
    if (local.ptr1) {
        _InterlockedExchangeAdd(&local.ptr1->refCount, 1);
    }
    local.ptr2 = src->ptr2;
    if (local.ptr2) {
        _InterlockedExchangeAdd(&local.ptr2->refCount, 1);
    }
    func_0071a850();
    if (local.ptr1) {
        if (_InterlockedExchangeAdd(&local.ptr1->refCount, -1) == 1) {
            void** vt = *(void***)local.ptr1;
            void (*fn)(void*) = (void (*)(void*))vt[2];
            fn(local.ptr1);
        }
    }
    if (local.ptr2) {
        if (_InterlockedExchangeAdd(&local.ptr2->refCount, -1) == 1) {
            void** vt = *(void***)local.ptr2;
            void (*fn)(void*) = (void (*)(void*))vt[2];
            fn(local.ptr2);
        }
    }
    local.str2.dtor();
    local.str1.dtor();

    return this;
}
