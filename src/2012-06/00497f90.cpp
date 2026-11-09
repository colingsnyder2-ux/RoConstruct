// from server: 37% by Intel
struct VSequence_sp_counted_impl_p {
    void* vftable;

    int f();
};

extern "C" void __cdecl sub_0067f480();
extern "C" void __cdecl sub_004015a0(int, int);
extern "C" void __cdecl sub_00495b00();
extern "C" int __cdecl sub_004019d0();
extern "C" int __cdecl sub_00466420(int);
extern "C" int __cdecl sub_00457100(int);
extern "C" int __cdecl sub_00972290(int, int);

int g_dword_00BB2F30;
int g_dword_00E1A8F4;
int g_dword_00E5809C;
char g_byte_00E580B3;

int VSequence_sp_counted_impl_p::f() {
    int v12;
    int v14;
    int v16;
    int v18;
    int esi;
    int edi;

    this->vftable = (void*)0x00B5F00C;
    if (!g_dword_00BB2F30) {
        sub_0067f480();
    } else {
        sub_004015a0(0x00E1A90C, 0x004965F0);
        sub_00495b00();
    }

    edi = sub_004019d0();
    if (!g_byte_00E580B3) {
        goto LABEL_10;
    }

    v12 = edi;
    int eax = sub_004019d0();
    esi = *(int*)(eax + 4);
    v14 = v12;
    v16 = v12;
    int ecx = sub_00466420(v14);
    if (*(int*)ecx != esi) {
        int eax2 = g_dword_00E5809C;
        if (eax2) {
            if (((int (__cdecl*)(int, int, int))eax2)(0x00B43284, 0x00B42FA8, 0xD7)) {
                goto LABEL_1;
            }
        }
        int edx = g_byte_00E580B3;
        sub_00972290(0x00B431E8, edx);
    }
LABEL_1:
    if (!g_byte_00E580B3) {
        goto LABEL_10;
    }
    if (g_dword_00E1A8F4 != 0x29A) {
        goto LABEL_10;
    }
    int eax3 = g_dword_00E5809C;
    if (eax3) {
        if (((int (__cdecl*)(int, int, int))eax3)(0x00B431D0, 0x00B42FA8, 0xD8)) {
            goto LABEL_2;
        }
    }
    int eax4 = g_byte_00E580B3;
    sub_00972290(0x00B43160, eax4);

LABEL_2:
    v18 = edi;
    int ecx2 = sub_004019d0();
    int ecx3 = sub_00457100(ecx2);
    *(int*)ecx3 = (int)this;
    if (!g_byte_00E580B3) {
        goto LABEL_11;
    }
    g_dword_00E1A8F4 = 0x29A;
    v12 = edi;
    int eax5 = sub_004019d0();
    int esi2 = *(int*)(eax5 + 4);
    v14 = v12;
    v16 = v12;
    int ecx4 = sub_00466420(v14);
    if (*(int*)ecx4 == esi2) {
        int eax6 = g_dword_00E5809C;
        if (eax6) {
            if (((int (__cdecl*)(int, int, int))eax6)(0x00B4311C, 0x00B42FA8, 0xDD)) {
                goto LABEL_3;
            }
        }
        int ecx5 = g_byte_00E580B3;
        sub_00972290(0x00B43080, ecx5);
    }
LABEL_3:
    if (!g_byte_00E580B3) {
        goto LABEL_11;
    }
    if (g_dword_00E1A8F4 == 0x29A) {
        goto LABEL_11;
    }
    int eax7 = g_dword_00E5809C;
    if (eax7) {
        if (((int (__cdecl*)(int, int, int))eax7)(0x00B42F90, 0x00B42FA8, 0xDE)) {
            goto LABEL_4;
        }
    }
    int edx2 = g_byte_00E580B3;
    sub_00972290(0x00B43010, edx2);

LABEL_4:
LABEL_11:
LABEL_10:
    return (int)this;
}
