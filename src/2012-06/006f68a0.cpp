// from server: 40% by Intel
struct VMotorFeature {
    int vtable;

    VMotorFeature* Creator();
};

extern "C" void __cdecl sub_0067f480();
extern "C" void __cdecl sub_004015a0(int, int);
extern "C" void __cdecl sub_006f3680();
extern "C" int __cdecl sub_004019d0();
extern "C" int __cdecl sub_00466420(int);
extern "C" int __cdecl sub_00457100(int);
extern "C" void __cdecl sub_00972290(int, int);

int g_dword_BDBB2C;
int g_dword_E30220;
int g_dword_E30230;
int g_dword_E5809C;
char g_byte_E580B3;
int g_dword_B9C598;

VMotorFeature* VMotorFeature::Creator() {
    int v12;
    int v14;
    int v16;
    VMotorFeature* this_ptr = this;
    this_ptr->vtable = g_dword_B9C598;

    if (!g_dword_BDBB2C) {
        sub_0067f480();
    } else {
        sub_004015a0(0x6F3DA0, g_dword_E30230);
        sub_006f3680();
    }

    int edi = sub_004019d0();

    if (g_byte_E580B3) {
        v12 = edi;
        int esi = *(int*)(sub_004019d0() + 4);
        int* v12_ptr = &v12;
        int* v14_ptr = &v14;
        int eax = sub_004019d0();
        int ecx = eax;
        int eax2 = sub_00466420(ecx);
        if (*(int*)eax2 != esi) {
            int eax3 = g_dword_E5809C;
            if (eax3) {
                if ((*(int(__cdecl**)(int, int, int))eax3)(0xD7, 0xB42FA8, 0xB43284)) {
                    goto LABEL_1;
                }
            }
            sub_00972290(g_byte_E580B3, 0xB431E8);
        }
    }
LABEL_1:
    if (g_byte_E580B3) {
        if (g_dword_E30220 == 0x29A) {
            int eax4 = g_dword_E5809C;
            if (eax4) {
                if ((*(int(__cdecl**)(int, int, int))eax4)(0xD8, 0xB42FA8, 0xB431D0)) {
                    goto LABEL_2;
                }
            }
            sub_00972290(g_byte_E580B3, 0xB43160);
        }
    }
LABEL_2:
    int* v12_ptr2 = &v12;
    v12 = edi;
    int ecx2 = sub_004019d0();
    int eax5 = sub_00457100(ecx2);
    *(int*)eax5 = (int)this_ptr;
    g_dword_E30220 = 0x29A;

    if (g_byte_E580B3) {
        v16 = edi;
        int esi2 = *(int*)(sub_004019d0() + 4);
        int* v16_ptr = &v16;
        int* v14_ptr2 = &v14;
        int eax6 = sub_004019d0();
        int ecx3 = eax6;
        int eax7 = sub_00466420(ecx3);
        if (*(int*)eax7 == esi2) {
            int eax8 = g_dword_E5809C;
            if (eax8) {
                if ((*(int(__cdecl**)(int, int, int))eax8)(0xDD, 0xB42FA8, 0xB4311C)) {
                    goto LABEL_3;
                }
            }
            sub_00972290(g_byte_E580B3, 0xB43080);
        }
    }
LABEL_3:
    if (g_byte_E580B3) {
        if (g_dword_E30220 != 0x29A) {
            int eax9 = g_dword_E5809C;
            if (eax9) {
                if ((*(int(__cdecl**)(int, int, int))eax9)(0xDE, 0xB42FA8, 0xB42F90)) {
                    goto LABEL_4;
                }
            }
            sub_00972290(g_byte_E580B3, 0xB43010);
        }
    }
LABEL_4:
    return this_ptr;
}
