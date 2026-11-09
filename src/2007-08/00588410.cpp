// from server: 33% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_77E6AC();
extern "C" void __cdecl sub_5402B0();

struct RefCounted {
    void** vptr;
    long refcount;
    long weakrefcount;
};

struct DecalGetSetImpl {
    void* vptr0;
    void* vptr4;
    char pad8[8];
    void* vptr10;
    void* vptr14;
    char pad18[0x18];
    void* vptr2c;
    char pad30[0x18];
    void* vptr44;
    char pad48[0x18];
    void* vptr5c;
    char pad60[0x18];
    void* vptr74;
    char pad78[0x14];
    void* vptr8c;
    char pad90[0x58];
    void* vptrE8;
    RefCounted* ptrF0;
    char padF4[4];
    char bufF8[0x10];

    void destroy();
};

void DecalGetSetImpl::destroy()
{
    this->vptr0 = (void*)0x7aeb04;
    this->vptr4 = (void*)0x7aeafc;
    this->vptr10 = (void*)0x7aeaf4;
    this->vptr14 = (void*)0x7aeae4;
    this->vptr2c = (void*)0x7aead4;
    this->vptr44 = (void*)0x7aeac4;
    this->vptr5c = (void*)0x7aeab4;
    this->vptr74 = (void*)0x7aeaa4;
    this->vptr8c = (void*)0x7aea94;
    this->vptrE8 = (void*)0x7aea88;

    sub_77E6AC();

    RefCounted* p = this->ptrF0;
    if (p != 0) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            void** vt = (void**)p->vptr;
            typedef void (__stdcall *Fn)(RefCounted*);
            ((Fn)vt[1])(p);
            if (_InterlockedExchangeAdd(&p->weakrefcount, -1) == 1) {
                void** vt2 = (void**)p->vptr;
                ((Fn)vt2[2])(p);
            }
        }
    }

    this->vptrE8 = (void*)0x795b60;
    this->vptr0 = (void*)0x7ae974;
    this->vptr4 = (void*)0x7ae96c;
    this->vptr10 = (void*)0x7ae964;
    this->vptr14 = (void*)0x7ae954;
    this->vptr2c = (void*)0x7ae944;
    this->vptr44 = (void*)0x7ae934;
    this->vptr5c = (void*)0x7ae924;
    this->vptr74 = (void*)0x7ae914;
    this->vptr8c = (void*)0x7ae904;

    sub_5402B0();
}
