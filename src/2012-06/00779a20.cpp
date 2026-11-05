// from server: 33% by Intel
struct VSelectionPartLasso {
    int vftable;
};

extern "C" void __cdecl sub_67F480();
extern "C" void __cdecl sub_4015A0(int, int);
extern "C" void __cdecl sub_767710();
extern "C" int __cdecl sub_4019D0(int*);
extern "C" int __cdecl sub_466420(int);
extern "C" int __cdecl sub_457100(int);
extern "C" int __cdecl sub_972290(int, int);

int g_dword_BEC990;
int g_dword_E5809C;
unsigned char g_byte_E580B3;
int g_dword_E379A0;

VSelectionPartLasso* VSelectionPartLasso_FactoryProduct_Creator(VSelectionPartLasso* this_ptr) {
    int v12;
    int v14;
    int v16;

    this_ptr->vftable = 0xBB0780;
    if (!g_dword_BEC990) {
        sub_67F480();
    } else {
        sub_4015A0(0x7680A0, 0xE37A48);
        sub_767710();
    }

    int edi = sub_4019D0(&v12);
    if (!g_byte_E580B3) {
        goto LABEL_779B0B;
    }

    int esi = *(int*)(edi + 4);
    sub_4019D0(&v14);
    if (*(int*)sub_466420(v14) != esi) {
        if (g_dword_E5809C) {
            if ((*(int(__cdecl**)(int, int, int))g_dword_E5809C)(0xD7, 0xB42FA8, 0xB43284)) {
                goto LABEL_779AC0;
            }
        }
        sub_972290(g_byte_E580B3, 0xB431E8);
    }

LABEL_779AC0:
    if (!g_byte_E580B3) {
        goto LABEL_779B0B;
    }
    if (g_dword_E379A0 != 0x29A) {
        goto LABEL_779B0B;
    }
    if (g_dword_E5809C) {
        if ((*(int(__cdecl**)(int, int, int))g_dword_E5809C)(0xD8, 0xB42FA8, 0xB431D0)) {
            goto LABEL_779B0B;
        }
    }
    sub_972290(g_byte_E580B3, 0xB43160);

LABEL_779B0B:
    sub_4019D0(&v16);
    *(int*)sub_457100(v16) = (int)this_ptr;
    g_dword_E379A0 = 0x29A;

    if (!g_byte_E580B3) {
        goto LABEL_779BE0;
    }

    edi = sub_4019D0(&v12);
    esi = *(int*)(edi + 4);
    sub_4019D0(&v14);
    if (*(int*)sub_466420(v14) == esi) {
        if (g_dword_E5809C) {
            if ((*(int(__cdecl**)(int, int, int))g_dword_E5809C)(0xDD, 0xB42FA8, 0xB4311C)) {
                goto LABEL_779B95;
            }
        }
        sub_972290(g_byte_E580B3, 0xB43080);
    }

LABEL_779B95:
    if (!g_byte_E580B3) {
        goto LABEL_779BE0;
    }
    if (g_dword_E379A0 == 0x29A) {
        goto LABEL_779BE0;
    }
    if (g_dword_E5809C) {
        if ((*(int(__cdecl**)(int, int, int))g_dword_E5809C)(0xDE, 0xB42FA8, 0xB42F90)) {
            goto LABEL_779BE0;
        }
    }
    sub_972290(g_byte_E580B3, 0xB43010);

LABEL_779BE0:
    return this_ptr;
}
