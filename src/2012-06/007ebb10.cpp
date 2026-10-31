// from server: 16% by Intel
struct VFrameFactoryProduct {
    char pad0[28];
    int field_1C;
    char pad1[8];
    int field_2C;
};

extern "C" int __stdcall sub_52AAC0();
extern "C" int __stdcall sub_6C8100(int);

int __stdcall VFrameFactoryProduct_Func(VFrameFactoryProduct* arg)
{
    if (!arg)
        return 0;

    VFrameFactoryProduct* esi = arg;
    if (!esi)
        return 0;

    int edi = esi->field_2C;
    int eax = sub_52AAC0();
    int ecx = edi;
    int result = sub_6C8100(ecx);

    if (!result)
        return 0;

    VFrameFactoryProduct* ecx2 = esi;
    if (!ecx2)
        return 0;

    int* vtable = *reinterpret_cast<int**>(ecx2);
    int (__stdcall *func)(VFrameFactoryProduct*) = reinterpret_cast<int (__stdcall*)(VFrameFactoryProduct*)>(vtable[0x54 / 4]);
    int ret = func(ecx2);

    return ret != 0;
}
