// from server: 40% by Intel
struct FactoryProduct {
    void* vftable;

    FactoryProduct* ctor();
};

extern "C" void __cdecl sub_67F480();
extern "C" void __cdecl sub_4015A0(int, int);
extern "C" void __cdecl sub_767DA0();
extern "C" int __cdecl sub_4019D0();
extern "C" int __cdecl sub_466420(int);
extern "C" int __cdecl sub_457100(int);
extern "C" int __cdecl sub_972290(int, int);
extern "C" int __cdecl sub_E5809C(int, int, int);

int g_dword_BC0BC0;
int g_dword_E379DC;
int g_dword_E5809C;
char g_byte_E580B3;

FactoryProduct* FactoryProduct::ctor() {
    int v12;
    int v14;
    FactoryProduct* this_ptr = this;
    int edi;
    int esi;
    int eax;

    this->vftable = (void*)0xBB0DF8;

    if (!g_dword_BC0BC0) {
        sub_67F480();
    } else {
        sub_4015A0(0x768190, 0xE37A84);
        sub_767DA0();
    }

    edi = sub_4019D0();

    if (g_byte_E580B3) {
        v12 = edi;
        eax = sub_4019D0();
        esi = *(int*)(eax + 4);
        eax = sub_4019D0();
        if (*(int*)sub_466420(eax) != esi) {
            if (g_dword_E5809C && sub_E5809C(0xD7, 0xB42FA8, 0xB43284)) {
            } else {
                sub_972290(g_byte_E580B3, 0xB431E8);
            }
        }
    }

    if (g_byte_E580B3 && g_dword_E379DC == 0x29A) {
        if (g_dword_E5809C && sub_E5809C(0xD8, 0xB42FA8, 0xB431D0)) {
        } else {
            sub_972290(g_byte_E580B3, 0xB43160);
        }
    }

    v14 = edi;
    eax = sub_4019D0();
    *(int*)sub_457100(eax) = (int)this_ptr;

    if (g_byte_E580B3) {
        g_dword_E379DC = 0x29A;
        v12 = edi;
        eax = sub_4019D0();
        esi = *(int*)(eax + 4);
        eax = sub_4019D0();
        if (*(int*)sub_466420(eax) == esi) {
            if (g_dword_E5809C && sub_E5809C(0xDD, 0xB42FA8, 0xB4311C)) {
            } else {
                sub_972290(g_byte_E580B3, 0xB43080);
            }
        }

        if (g_byte_E580B3 && g_dword_E379DC != 0x29A) {
            if (g_dword_E5809C && sub_E5809C(0xDE, 0xB42FA8, 0xB42F90)) {
            } else {
                sub_972290(g_byte_E580B3, 0xB43010);
            }
        }
    }

    return this_ptr;
}
