// from server: 43% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VMarkerSignalDesc {
    int field0;
    int field4;
    char pad8[0x20];
    void construct(int* src);
};

extern "C" void __cdecl sub_4b3030();
extern "C" void* __cdecl sub_62fef6(unsigned int size);
extern "C" void __cdecl sub_4181b0(void* p);
extern "C" void __cdecl sub_728830();

void VMarkerSignalDesc::construct(int* src)
{
    field0 = 0;
    field4 = 0;

    int* p = src;
    int v0 = p[0];
    int v1 = p[1];

    int* tmp = (int*)&pad8[0];
    tmp[0] = v0;
    tmp[1] = v1;

    if (v1 != 0) {
        _InterlockedExchangeAdd((volatile long*)(v1 + 4), 1);
    }

    sub_4b3030();

    void* obj = sub_62fef6(0x20);
    if (obj != 0) {
        *(int*)((char*)obj + 4) = 0;
        *(int*)((char*)obj + 8) = 0;
        *(int*)((char*)obj + 0xc) = 0;
        *(int*)((char*)obj + 0x14) = 0;
        *(int*)((char*)obj + 0x18) = 0;
        *(char*)((char*)obj + 0x1c) = 0;
    } else {
        obj = 0;
    }

    sub_4181b0(obj);
    sub_728830();
}
