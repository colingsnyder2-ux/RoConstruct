// from server: 46% by colin
struct CXTPDockingPaneTabbedContainer {
    char pad0[0x20];
    int m_flag20;
    char pad1[0x30];
    char m_field54[0x54];
    char pad2[0x2c];
    int m_field80;
    char pad3[0x24];
    char m_fieldA8[0xa8];
    char pad4[0x5c];
    int m_field104;
    char pad5[0x90];
    int m_field198;
    char pad6[0x4];
    int m_field1A0;
    void f();
};

extern "C" {
    int __stdcall sub_65E560(int);
    int __stdcall sub_68F1B0(int);
    int __stdcall sub_6E0580(int, int, int);
    int __stdcall sub_6FD1A0(int, int);
    int __stdcall sub_6FD590(int, int);
    int __stdcall sub_6FD5C0(int, int);
    int __stdcall sub_6FE640(int);
    int __stdcall sub_6FE6B0(int, int, int);
    int __stdcall sub_71FA60(int, int);
    int __stdcall sub_77DD6C(int, int);
    int __stdcall sub_77DD98(int);
    int __stdcall sub_77DDBC(int);
}

void CXTPDockingPaneTabbedContainer::f() {
    if (this->m_flag20 == 0)
        return;

    this->m_field198++;

    sub_6FE640((int)(this->m_fieldA8));

    int v = sub_65E560((int)(this->m_field54));
    if (v != 0) {
        do {
            int eax = sub_71FA60((int)(this->m_field54), (int)&v);
            int esi;
            if (eax != 0)
                esi = eax - 0x20;
            else
                esi = 0;

            int edi = sub_6FE6B0((int)(this->m_fieldA8), this->m_field104, 0);

            if (this->m_field1A0 == esi) {
                int edx = *(int*)(this->m_fieldA8);
                int eax2 = *(int*)(edx + 0x20);
                sub_6FE6B0((int)(this->m_fieldA8), edi, 0);
                ((int (__stdcall*)(int, int))eax2)((int)(this->m_fieldA8), edi);
            }

            int edx2 = *(int*)esi;
            int edx3 = *(int*)(edx2 + 0x60);
            int tmp;
            ((int (__stdcall*)(int, int))edx3)(esi, (int)&tmp);
            int ecx = sub_77DD98((int)&tmp);
            sub_6FD590(edi, ecx);
            sub_77DDBC((int)&tmp);

            int eax3 = *(int*)esi;
            int edx4 = *(int*)(eax3 + 0x68);
            int r = ((int (__stdcall*)(int))edx4)(esi);
            sub_6FD5C0(edi, r);

            int eax4 = *(int*)esi;
            int edx5 = *(int*)(eax4 + 0x5c);
            int tmp2;
            ((int (__stdcall*)(int, int))edx5)(esi, (int)&tmp2);
            int ecx2 = sub_77DD98((int)&tmp2);
            sub_77DD6C(edi + 0x58, ecx2);
            sub_77DDBC((int)&tmp2);

            int r2 = sub_68F1B0(esi);
            sub_6FD1A0(edi, r2 & 1);

            *(int*)(edi + 0x40) = esi;
        } while (v != 0);
    }

    sub_6E0580(this->m_field80, -1, -1);
    this->m_field198--;
}
