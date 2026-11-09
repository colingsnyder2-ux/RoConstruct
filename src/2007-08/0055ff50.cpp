// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long refCount;
    long weakRefCount;
};

struct SubObject {
    void** vptr;
};

struct FilteredSelection {
    void** vptr0;
    void** vptr4;
    char pad[0xe8 - 8];
    void** vptrE8;
    void* ptrEC;
    void* ptrF0;
    void* ptrF4;
    void* ptrF8;
    void* ptrFC;
    void* ptr100;
    void destructor();
};

extern "C" void __cdecl sub_532550(void*);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __cdecl sub_5402B0(void*);

void FilteredSelection::destructor()
{
    this->vptr0 = (void**)0x7a92a4;
    this->vptr4 = (void**)0x7a9298;
    *(void***)((char*)this + 0x10) = (void**)0x7a9290;
    *(void***)((char*)this + 0x14) = (void**)0x7a9280;
    *(void***)((char*)this + 0x2c) = (void**)0x7a9270;
    *(void***)((char*)this + 0x44) = (void**)0x7a9260;
    *(void***)((char*)this + 0x5c) = (void**)0x7a9250;
    *(void***)((char*)this + 0x74) = (void**)0x7a9240;
    *(void***)((char*)this + 0x8c) = (void**)0x7a9230;
    this->vptrE8 = (void**)0x7a9228;

    if (this->ptrEC != 0) {
        sub_532550(&this->vptrE8);
    }

    if (this->ptrF8 != 0) {
        sub_62FC62(this->ptrF8);
    }
    this->ptrF8 = 0;
    this->ptrFC = 0;
    this->ptr100 = 0;

    RefCounted* p = (RefCounted*)this->ptrF0;
    if (p != 0) {
        if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
            void** vt = p->vptr;
            void (*fn)(RefCounted*) = (void (*)(RefCounted*))vt[1];
            fn(p);
        }
        if (_InterlockedExchangeAdd(&p->weakRefCount, -1) == 1) {
            void** vt = p->vptr;
            void (*fn)(RefCounted*) = (void (*)(RefCounted*))vt[2];
            fn(p);
        }
    }

    sub_5402B0(this);
}
