// from server: 27% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VObjectValue {
    void* vptr;
    char pad[8];
};

struct RefCounted {
    long refCount;
};

extern "C" int __stdcall sub_86E970(int);

int __stdcall VObjectValue_FactoryProduct(VObjectValue* thisptr, int a2, int a3, int a4)
{
    RefCounted* rc = reinterpret_cast<RefCounted*>(reinterpret_cast<char*>(thisptr) + 8);
    rc->refCount = a2;

    int v = a4;
    if (v) {
        long old = _InterlockedExchangeAdd(&reinterpret_cast<RefCounted*>(v)->refCount, 1);
        (void)old;
    }

    int result = sub_86E970(0xD7D244);
    unsigned char al = static_cast<unsigned char>(result);
    int eax = -static_cast<int>(al);
    eax = (eax >> 31) & 0xD7D244;
    thisptr->vptr = reinterpret_cast<void*>(eax);

    v = a3;
    if (v) {
        long old = _InterlockedExchangeAdd(&reinterpret_cast<RefCounted*>(v)->refCount, -1);
        if (old == 1) {
            int (*destructor)(RefCounted*) = *reinterpret_cast<int (**)(RefCounted*)>(*reinterpret_cast<int**>(v) + 8);
            destructor(reinterpret_cast<RefCounted*>(v));
        }
    }

    return reinterpret_cast<int>(thisptr);
}
