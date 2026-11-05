// from server: 30% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ErrData {
    char pad0[4];
    char pad1[4];
};

struct ErrUploader {
    void* _data;
    void* thread;
    ErrUploader* ctor(ErrData* d);
};

struct Inner {
    char pad[8];
};

extern "C" void __stdcall sub_488c60(void*, void*);
extern "C" void __stdcall sub_572440(void*, void*, void*);
extern "C" void __cdecl sub_44b0c0(void*);

ErrUploader* ErrUploader::ctor(ErrData* d)
{
    void* p = _data;
    if (p != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    }
    sub_488c60((void*)0x41b830, this);
    sub_44b0c0((void*)((char*)this + 0x28));
    sub_572440((void*)((char*)this + 8), (void*)0x7909f4, (void*)((char*)this + 0x1c));
    return this;
}
