// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ClientProxy {
    void* field0;
    void* field4;
    char pad8[0x18];
    void construct(void* arg);
};

extern void __stdcall sub_4181b0(void*);
extern void __stdcall sub_4b27e0(void*);
extern void* __cdecl sub_62fef6(unsigned int);
extern void __stdcall sub_728830(void*);

void ClientProxy::construct(void* arg)
{
    field0 = 0;
    field4 = 0;

    void** src = (void**)arg;
    void* a = src[0];
    void* b = src[1];

    void* local[2];
    local[0] = a;
    local[1] = b;
    if (b != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }

    sub_4b27e0((char*)this + 8);

    void* p = sub_62fef6(0x20);
    if (p != 0) {
        *(void**)((char*)p + 4) = 0;
        *(void**)((char*)p + 8) = 0;
        *(void**)((char*)p + 0xc) = 0;
        *(void**)((char*)p + 0x14) = 0;
        *(void**)((char*)p + 0x18) = 0;
        *(char*)((char*)p + 0x1c) = 0;
    } else {
        p = 0;
    }

    sub_4181b0(p);
    sub_728830(this);
}
