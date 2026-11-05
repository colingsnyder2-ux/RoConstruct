// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_004ab8d0();
extern "C" void __cdecl sub_005402b0();
extern "C" void __cdecl sub_00541c30();
extern "C" void __cdecl sub_0056a5b0();
extern "C" void __cdecl sub_00588670();
extern "C" void __cdecl sub_00589ef0();
extern "C" void __cdecl sub_0062fc1a();
extern "C" void __cdecl sub_0062fc62();

struct VStockSound_FactoryProduct {
    void destructor();
};

void VStockSound_FactoryProduct::destructor()
{
    char* self = (char*)this;
    *(void**)(self + 0) = (void*)0x7aecbc;
    *(void**)(self + 4) = (void*)0x7aecb0;
    *(void**)(self + 0x10) = (void*)0x7aeca8;
    *(void**)(self + 0x14) = (void*)0x7aec98;
    *(void**)(self + 0x2c) = (void*)0x7aec88;
    *(void**)(self + 0x44) = (void*)0x7aec78;
    *(void**)(self + 0x5c) = (void*)0x7aec68;
    *(void**)(self + 0x74) = (void*)0x7aec58;
    *(void**)(self + 0x8c) = (void*)0x7aec48;
    *(void**)(self + 0xe8) = (void*)0x7aec3c;

    char* ebp = self + 0xf4;
    void* eax = *(void**)(self + 0xf8);
    void* ecx = *(void**)((char*)eax + 4);
    sub_004ab8d0();
    eax = *(void**)(ebp + 4);
    *(void**)((char*)eax + 4) = eax;
    eax = *(void**)(ebp + 4);
    *(void**)(ebp + 8) = 0;
    *(void**)eax = eax;
    eax = *(void**)(ebp + 4);
    *(void**)((char*)eax + 8) = eax;
    sub_00541c30();

    char* edi = self + 0x120;
    eax = *(void**)(self + 0x124);
    sub_00588670();
    char* ebx = self + 0x12c;
    eax = *(void**)(self + 0x130);
    sub_00588670();

    eax = *(void**)(self + 0xec);
    if (eax != 0) {
        sub_0062fc1a();
    }

    eax = *(void**)(ebx + 4);
    ecx = *(void**)eax;
    sub_00589ef0();
    eax = *(void**)(ebx + 4);
    sub_0062fc62();
    *(void**)(ebx + 4) = 0;
    *(void**)(ebx + 8) = 0;

    eax = *(void**)(edi + 4);
    ecx = *(void**)eax;
    sub_00589ef0();
    eax = *(void**)(edi + 4);
    sub_0062fc62();
    *(void**)(edi + 4) = 0;
    *(void**)(edi + 8) = 0;

    edi = *(char**)(self + 0x110);
    if (edi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)(edi + 4), -1) == 1) {
            eax = *(void**)edi;
            void* edx = *(void**)((char*)eax + 4);
            ((void (__thiscall*)(void*))edx)(edi);
            eax = edi + 8;
            if (_InterlockedExchangeAdd((volatile long*)eax, -1) == 1) {
                void* edx2 = *(void**)edi;
                void* eax2 = *(void**)((char*)edx2 + 8);
                ((void (__thiscall*)(void*))eax2)(edi);
            }
        }
    }

    eax = *(void**)(ebp + 4);
    ecx = *(void**)eax;
    sub_0056a5b0();
    eax = *(void**)(ebp + 4);
    sub_0062fc62();
    *(void**)(ebp + 4) = 0;
    *(void**)(ebp + 8) = 0;

    *(void**)(self + 0xe8) = (void*)0x795b60;
    *(void**)(self + 0) = (void*)0x7ae8bc;
    *(void**)(self + 4) = (void*)0x7ae8b0;
    *(void**)(self + 0x10) = (void*)0x7ae8a8;
    *(void**)(self + 0x14) = (void*)0x7ae898;
    *(void**)(self + 0x2c) = (void*)0x7ae888;
    *(void**)(self + 0x44) = (void*)0x7ae878;
    *(void**)(self + 0x5c) = (void*)0x7ae868;
    *(void**)(self + 0x74) = (void*)0x7ae858;
    *(void**)(self + 0x8c) = (void*)0x7ae848;
    sub_005402b0();
}
