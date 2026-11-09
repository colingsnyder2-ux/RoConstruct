// from server: 30% by colin
// roc 2007-08 006dcef0 451 bytes
// CXTPDockingPaneWindowSelect::OnLButtonDown or similar

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int vKey);

struct CXTPDockingPaneWindowSelect {
    void sub_6d2910(void* p);
    void sub_6dc270(void* p);
    void sub_63002e(int a, int b, int c, int d, int e, int f);
    void sub_630940();
    void sub_67ffa0(void* p);
    int __cdecl OnLButtonDown(int x, int y, int flags);
};

void CXTPDockingPaneWindowSelect::sub_6d2910(void* p) {}
void CXTPDockingPaneWindowSelect::sub_6dc270(void* p) {}
void CXTPDockingPaneWindowSelect::sub_63002e(int a, int b, int c, int d, int e, int f) {}
void CXTPDockingPaneWindowSelect::sub_630940() {}
void CXTPDockingPaneWindowSelect::sub_67ffa0(void* p) {}

int CXTPDockingPaneWindowSelect::OnLButtonDown(int x, int y, int flags)
{
    int local_10;
    int local_14;
    int local_18;
    int local_1c;
    int local_20;
    int local_24;
    int local_28;
    int local_2c;
    int local_30;
    int local_34;
    int local_38;
    int local_3c;
    int local_40;
    int local_44;
    int local_48;
    int local_4c;
    int local_50;
    int local_54;
    int local_58;
    int local_5c;
    int local_60;
    int local_64;
    int local_68;
    int local_6c;

    int ebx = 0;
    int ebp = 0;

    int eax_val = 0;
    if (*(int*)((char*)this + 0xcc) != 0) {
        eax_val = *(int*)(*(int*)((char*)this + 0xcc) + 0x20);
    }

    int edx_val = local_28;
    *(int*)((char*)this + 0x00) = edx_val;
    *(int*)((char*)this + 0x10) = eax_val;
    *(int*)((char*)this + 0x04) = ebp;
    int eax2 = edx_val + 0xa3;
    int ecx2 = ebx + ebp;
    *(int*)((char*)this + 0x08) = eax2;
    *(int*)((char*)this + 0x0c) = ecx2;

    int ecx3 = (int)((char*)this + 0xe8);
    *(int*)((char*)this + 0x20) = 2;
    int ebp2 = *(int*)(ecx3 + 8);
    sub_6d2910((void*)ebp2);
    int edx3 = local_20;
    *(int*)((char*)this + 0x14) = ebp2;
    *(int*)((char*)this + 0x18) = edx3;
    *(int*)((char*)this + 0x1c) = 0;

    if (*(int*)((char*)this + 0x110) == 0) {
        *(int*)((char*)this + 0x110) = (int)this;
    }
    *(int*)((char*)this + 0x11c) += 1;

    int esi2 = local_18;
    int eax4 = *(int*)((char*)this + 0xf0);
    if (esi2 < eax4) {
        eax4 -= 1;
        int ecx4 = (int)((char*)this + 0xfc);
        int edx4 = (int)&local_14;
        local_14 = eax4;
        int eax5 = *(int*)(ecx4 + 8);
        local_18 = esi2;
        sub_6dc270((void*)eax5);
    }

    int eax6 = *(int*)((char*)this + 0xf0);
    eax6 -= 1;
    if (*(int*)((char*)this + 0x11c) < eax6) {
        if (*(int*)((char*)this + 0x13c) == 0) {
            if (GetKeyState(0x10) < 0) {
                int eax7 = *(int*)((char*)this + 0xf0);
                eax7 -= 1;
                goto label_cfb7;
            }
            int eax8 = *(int*)((char*)this + 0x11c);
            eax8 += 1;
            if (eax8 < 0) goto label_ccf8;
            if (eax8 >= *(int*)((char*)this + 0xf0)) goto label_ccf8;
            int ecx5 = *(int*)((char*)this + 0xec);
            int edx5 = *(int*)(ecx5 + eax8 * 4);
            *(int*)((char*)this + 0x110) = edx5;
        }
    }
    goto label_cfdb;

label_ccf8:
    {
        int eax9 = *(int*)((char*)this + 0xf0);
        eax9 -= 1;
        goto label_cfb7;
    }

label_cfb7:
    {
        int eax10 = *(int*)((char*)this + 0x11c);
        eax10 += 1;
        if (eax10 < 0) goto label_ccf8;
        if (eax10 >= *(int*)((char*)this + 0xf0)) goto label_ccf8;
        int ecx6 = *(int*)((char*)this + 0xec);
        int edx6 = *(int*)((ecx6 + eax10 * 4));
        *(int*)((char*)this + 0x110) = edx6;
    }

label_cfdb:
    {
        int eax11 = local_2c;
        if (eax11 > local_1c) {
            local_1c = eax11;
        }
        int eax12 = *(int*)((char*)this + 0x104);
        if (eax12 < 2) {
            eax12 = 2;
        }
        int ecx7 = *(int*)((char*)this + 0xe4);
        eax12 *= 0xaf;
        eax12 += 4;
        int ebp3 = eax12;
        int eax13 = ebx + 1;
        eax13 *= local_1c;
        ebx = eax13 + ebx + 0x7b;
        int eax14 = *(int*)(ecx7 + 0xcc);
        sub_67ffa0((void*)eax14);

        int edx7 = local_10;
        int eax15 = local_18;
        eax15 += edx7;
        eax15 -= edx7;
        int edx8 = local_1c;
        int ecx8 = eax15;
        int eax16 = local_14;
        eax16 += edx8;
        eax16 -= edx8;
        int esi3 = eax16;
        int eax17 = ebx;
        eax17 -= (eax17 >> 31);
        eax17 >>= 1;
        ecx8 -= (ecx8 >> 31);
        ecx8 >>= 1;
        ecx8 -= eax17;
        int eax18 = ebp3;
        eax18 -= (eax18 >> 31);
        eax18 >>= 1;
        int edx9 = ecx8 + ebx;
        esi3 -= (esi3 >> 31);
        esi3 >>= 1;
        esi3 -= eax18;
        edx9 -= ecx8;
        int eax19 = esi3 + ebp3;
        eax19 -= esi3;

        sub_63002e(ecx8, esi3, eax19, edx9, 0x250, 0);

        local_6c = -1;
        sub_630940();
        return 1;
    }
}
