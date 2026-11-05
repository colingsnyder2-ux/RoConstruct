// from server: 57% by colin
extern "C" {
int __stdcall wsprintfA(char* buffer, const char* format, ...);
}

struct CXTPDockingPaneAutoHidePanel {
    char pad_0000[0x0c];
    int* m_pArray;
    char pad_0010[0x2c];
    int m_nCount;
    char pad_0040[0x04];
    int m_nSome;
    char pad_0048[0x10];
    int m_nIndex;
    char pad_005c[0xac];
    int m_nField;

    int sub_6D9360(int a2);
};

extern "C" int __stdcall sub_6D7B90(int);
extern "C" int __stdcall sub_685740(int, const char*, int);
extern "C" int __stdcall sub_685720(int, const char*, int, int);
extern "C" int __stdcall sub_6353A0(int, int);
extern "C" int __stdcall sub_630A1E();

int CXTPDockingPaneAutoHidePanel::sub_6D9360(int a2)
{
    char buffer[0x100];
    int local10;
    int local14;
    int local18;
    int local1c;
    int local20;
    int local24;
    int local28;
    int local2c;
    int local30;
    int local34;
    int local38;
    int local3c;
    int local40;
    int local44;
    int local48;
    int local4c;
    int local50;
    int local54;
    int local58;
    int local5c;
    int local60;
    int local64;
    int local68;
    int local6c;
    int local70;
    int local74;
    int local78;
    int local7c;
    int local80;
    int local84;
    int local88;
    int local8c;
    int local90;
    int local94;
    int local98;
    int local9c;
    int locala0;
    int locala4;
    int locala8;
    int localac;
    int localb0;
    int localb4;
    int localb8;
    int localbc;
    int localc0;
    int localc4;
    int localc8;
    int localcc;
    int locald0;
    int locald4;
    int locald8;
    int localdc;
    int locale0;
    int locale4;
    int locale8;
    int localec;
    int localf0;
    int localf4;
    int localf8;
    int localfc;
    int local100;
    int local104;
    int local108;
    int local10c;

    local10c = 0;
    local10 = 0;
    local14 = 0;
    local18 = 0;
    local1c = 0;
    local20 = 0;
    local24 = 0;
    local28 = 0;
    local2c = 0;
    local30 = 0;
    local34 = 0;
    local38 = 0;
    local3c = 0;
    local40 = 0;
    local44 = 0;
    local48 = 0;
    local4c = 0;
    local50 = 0;
    local54 = 0;
    local58 = 0;
    local5c = 0;
    local60 = 0;
    local64 = 0;
    local68 = 0;
    local6c = 0;
    local70 = 0;
    local74 = 0;
    local78 = 0;
    local7c = 0;
    local80 = 0;
    local84 = 0;
    local88 = 0;
    local8c = 0;
    local90 = 0;
    local94 = 0;
    local98 = 0;
    local9c = 0;
    locala0 = 0;
    locala4 = 0;
    locala8 = 0;
    localac = 0;
    localb0 = 0;
    localb4 = 0;
    localb8 = 0;
    localbc = 0;
    localc0 = 0;
    localc4 = 0;
    localc8 = 0;
    localcc = 0;
    locald0 = 0;
    locald4 = 0;
    locald8 = 0;
    localdc = 0;
    locale0 = 0;
    locale4 = 0;
    locale8 = 0;
    localec = 0;
    localf0 = 0;
    localf4 = 0;
    localf8 = 0;
    localfc = 0;
    local100 = 0;
    local104 = 0;
    local108 = 0;

    sub_6D7B90(a2);

    local18 = this->m_nField;
    sub_685740(a2, (const char*)0x7d8d58, (int)&local14);

    if (*(int*)(a2 + 0x24) != 0) {
        local1c = this->m_nSome;
        sub_685740(a2, (const char*)0x7d8bf4, (int)&local10);
        int ebx = 1;
        int* esi = (int*)this->m_nCount;
        if (esi != 0) {
            do {
                int* eax = esi;
                esi = (int*)*esi;
                int ebp = *(int*)((char*)eax + 8);
                wsprintfA(buffer, (const char*)0x7d8bec, ebx);
                ebp += 0x34;
                sub_685740(a2, (const char*)buffer, ebp);
                ebx++;
            } while (esi != 0);
        }
    } else {
        local18 = local14;
        this->m_nField = local18;
        sub_685720(a2, (const char*)0x7d8bf4, (int)&local10, 0);
        int ebx = *(int*)(a2 + 0x20);
        local28 = 0;
        int esi = 1;
        if (local10 >= esi) {
            do {
                wsprintfA(buffer, (const char*)0x7d8bec, esi);
                sub_685720(a2, (const char*)buffer, (int)&local20, 0);
                int edx = local20;
                int eax = sub_6353A0(ebx, edx);
                eax = *(int*)eax;
                if (eax == 0) {
                    return 0;
                }
                int* edx2 = *(int**)((char*)this + 0xac);
                int* ecx2 = (int*)((char*)this + 0xac);
                int (*fn)(int) = *(int (**)(int))((char*)edx2 + 0x140);
                fn(eax);
                esi++;
            } while (esi <= local10);
        }
        int edx3 = this->m_nField;
        int eax3 = *(int*)((char*)this + 0x0c);
        *(int*)(eax3 + edx3 * 4 + 0x60) = (int)((char*)this + 0xac);
    }

    return 1;
}
