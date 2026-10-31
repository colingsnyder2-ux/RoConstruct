// from server: 73% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int vptr;
    long refCount;
};

struct BuilderLevelGenFunc {
    int vptr;
    int field_4;
    int field_8;
    float field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};

BuilderLevelGenFunc* __stdcall BuilderLevelGenFunc_ctor(
    BuilderLevelGenFunc* thisptr,
    int a1,
    RefCounted* a2,
    int a3,
    float a4,
    RefCounted* a5
) {
    thisptr->vptr = 0xB6AA6C;
    thisptr->field_4 = a1;
    thisptr->field_8 = a3;
    thisptr->field_C = a4;

    int vptr2 = a2->vptr;
    thisptr->field_10 = vptr2;
    RefCounted* rc2 = (RefCounted*)a2->refCount;
    thisptr->field_14 = (int)rc2;
    if (rc2) {
        _InterlockedExchangeAdd(&rc2->refCount, 1);
    }

    int vptr5 = a5->vptr;
    thisptr->field_18 = vptr5;
    RefCounted* rc5 = (RefCounted*)a5->refCount;
    thisptr->field_1C = (int)rc5;
    if (rc5) {
        _InterlockedExchangeAdd(&rc5->refCount, 1);
    }

    return thisptr;
}
