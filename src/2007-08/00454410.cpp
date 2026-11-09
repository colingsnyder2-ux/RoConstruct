// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct VInstance {
    void* vptr;
    int field_04;
    RefCounted* field_08;
    int field_0c;
    RefCounted* field_14;
    void destroy();
};

extern "C" void __cdecl sub_437B80(VInstance*);

void VInstance::destroy()
{
    this->vptr = (void*)0x7921e4;
    if (this->field_0c) {
        sub_437B80(this);
    }
    RefCounted* p14 = this->field_14;
    if (p14) {
        if (_InterlockedExchangeAdd(&p14->refCount, -1) == 1) {
            void** vt = (void**)p14->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(p14);
            if (_InterlockedExchangeAdd(&p14->weakCount, -1) == 1) {
                void** vt2 = (void**)p14->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(p14);
            }
        }
    }
    RefCounted* p08 = this->field_08;
    if (p08) {
        if (_InterlockedExchangeAdd(&p08->refCount, -1) == 1) {
            void** vt = (void**)p08->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(p08);
            if (_InterlockedExchangeAdd(&p08->weakCount, -1) == 1) {
                void** vt2 = (void**)p08->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(p08);
            }
        }
    }
    this->vptr = (void*)0x787f68;
}
