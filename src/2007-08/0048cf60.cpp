// from server: 29% by colin
struct Creator {
    char pad0[0x130];
    char pad1[8];
    char pad2[8];
    char pad3[8];
    int f();
};

extern "C" void __stdcall sub_725520(void*, void*);
extern "C" void __cdecl sub_4874a0();
extern "C" void __cdecl sub_40e470();
extern "C" void __cdecl sub_486c70();
extern "C" void __cdecl sub_52cb30();
extern "C" void __cdecl sub_554de0();
extern "C" void __cdecl sub_492360();
extern "C" void __cdecl sub_402a60();
extern "C" void __cdecl _invalid_parameter_noinfo();

extern unsigned char byte_8BDCE4;
extern unsigned char byte_8BDCE8;
extern unsigned char byte_8BDC90;
extern unsigned char byte_8BDCCC;
extern unsigned char byte_8B5188;

int Creator::f()
{
    void* p = &byte_8BDCCC;
    sub_725520(p, (void*)0x487bf0);
    sub_4874a0();
    int ebp = 0;
    char* esi = pad0 + 0x130;
    int ecx = *(int*)(pad0 + 0x134);
    int eax;
    if (ecx == 0) {
        eax = 0;
    } else {
        eax = *(int*)(esi + 8) - ecx;
        eax >>= 3;
    }
    int ecx2 = ebp + 1;
    if ((unsigned)ecx2 <= (unsigned)eax) {
        int ecx3 = *(int*)(esi + 4);
        if (ecx3 == 0 || ebp >= (*(int*)(esi + 8) - ecx3) >> 3) {
            _invalid_parameter_noinfo();
        }
        eax = *(int*)(*(int*)(esi + 4) + ebp * 8);
        if (eax != 0) {
            return eax;
        }
    } else {
        int tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_40e470();
    }
    if ((byte_8BDCE8 & 1) == 0) {
        byte_8BDCE8 |= 1;
        sub_725520(&byte_8BDC90, (void*)0x487900);
        sub_486c70();
        int edi = eax;
        sub_52cb30();
        byte_8BDCE4 = (edi == eax);
    }
    if (byte_8BDCE4 == 0) {
        sub_725520(&byte_8BDC90, (void*)0x487900);
        sub_486c70();
        sub_554de0();
        int ecx4 = *(int*)(esi + 4);
        if (ecx4 == 0 || ebp >= (*(int*)(esi + 8) - ecx4) >> 3) {
            _invalid_parameter_noinfo();
        }
        int* edx = (int*)(*(int*)(esi + 4) + ebp * 8);
        *edx = ecx4;
        sub_402a60();
        sub_492360();
        return ecx4;
    }
    return 0;
}
