// from server: 33% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall _invalid_parameter_noinfo();

struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

struct S {
    char pad0[4];
    char* field4;
    char* field8;
    void func(int);
};

extern "C" {
    int __cdecl sub_4aaa10(void*, void*);
    int __cdecl sub_4a6150(int, int);
    int __cdecl sub_4a0df0(int, int, int);
    int __cdecl sub_498f60();
    int __cdecl sub_56c3b0(void*);
    int __cdecl sub_4a41a0(int, int);
    int __cdecl sub_4a3510(int, int, int, int);
    int __cdecl sub_56c0a0(int, int, int, int);
    int __cdecl sub_4a2070(int, int, int);
    int __cdecl sub_4a0230(int, int);
    int __cdecl sub_4b0cd0(int, int);
    int __cdecl sub_4b3f00(int, int, int, int);
}

void S::func(int a)
{
    int local14;
    int local18;
    int local20;
    int local24;
    int local2c;
    int local38;
    int local3c;
    int local48;
    int local50;

    local50 = a;

    local18 = (int)field8;
    if (sub_4aaa10((void*)(field4 + 0x1d9c), &local14) == 0)
        return;

    sub_4a6150(local50, 2);
    sub_4a0df0((int)(field4 + 0xec), local50, (int)field8);

    int r = sub_498f60();
    if (*(char*)(r + 0xf4) != 0) {
        int edi = (int)field8;
        int ebp = sub_56c3b0(&local18);
        local14 = (int)field8;
        int eax = (*(int(**)(void))((*(int*)edi) + 4))();
        int ebx;
        if (*(int*)(eax + 0x1c) >= 0x10)
            ebx = *(int*)(eax + 8);
        else
            ebx = eax + 8;
        int edi2 = *(int*)ebp;
        int eax2 = sub_4a41a0(*(int*)(field4 + 0xec), local14);
        int eax3 = sub_4a3510((int)(field4 + 0x1e18), 1, ebx, eax2);
        sub_56c0a0(edi2, 1, 0x79dedc, eax3);

        int eax4 = local20;
        local48 = -1;
        if (eax4 != 0) {
            int edi3 = eax4;
            eax4 += 4;
            if (_InterlockedExchangeAdd((volatile long*)eax4, -1) == 1) {
                int edx = *(int*)edi3;
                (*(int(**)(void))((*(int*)edx) + 4))();
                int ecx = edi3 + 8;
                if (_InterlockedExchangeAdd((volatile long*)ecx, -1) == 1) {
                    int eax5 = *(int*)edi3;
                    (*(int(**)(void))((*(int*)eax5) + 8))();
                }
            }
        }
    }

    int ecx2 = (int)field8;
    int eax6 = *(int*)ecx2;
    int edi4 = (*(int(**)(void))((*(int*)eax6) + 4))();
    sub_4a2070((int)(field4 + 0x12c), local50, edi4 + 4);

    int eax7 = (int)field8;
    int edx2 = *(int*)field4;
    char al = (*(char(**)(int))((*(int*)edx2) + 0x50))(eax7);
    local14 = al;
    sub_4a0230(local50, local14);

    int eax8 = sub_4b0cd0((int)field4, edi4);
    local18 = eax8;

    int ebp2 = (int)field8;
    int edi5 = *(int*)(ebp2 + 0xc);
    int ebx2 = *(int*)(edi5 + 0xc);
    ebp2 += 4;
    edi5 += 8;
    if (ebx2 > *(int*)(edi5 + 8))
        _invalid_parameter_noinfo();
    local38 = edi5;
    int edi6 = ebx2;

    int eax9 = (int)field8 + 4;
    int ebx3 = *(int*)(eax9 + 8);
    int eax10 = *(int*)(ebx3 + 0x10);
    ebx3 += 8;
    if (*(int*)(ebx3 + 4) > eax10)
        _invalid_parameter_noinfo();
    local3c = edi6;
    local14 = eax10;

    while (1) {
        int eax11 = local38;
        if (eax11 != 0 && eax11 == ebx3) {
        } else {
            _invalid_parameter_noinfo();
        }
        if (edi6 == local14)
            break;

        if (local38 == 0)
            _invalid_parameter_noinfo();
        if (edi6 < *(int*)(local38 + 8))
            _invalid_parameter_noinfo();

        int eax12 = *(int*)edi6;
        local20 = eax12;
        local24 = ebp2;
        int ecx3 = *(int*)(eax12 + 0x10);
        ecx3 >>= 1;
        if ((ecx3 & 1) != 0) {
            int eax13 = *(int*)(eax12 + 0x14);
            int edx3 = *(int*)(eax13 + 8);
            if (((type_info*)0x8827e0)->operator==(*(type_info*)edx3)) {
                sub_4b3f00((int)field4, (int)&local20, 0, local50);
            } else {
                int edx4 = local18;
                if (edx4 != 0) {
                    int eax14 = (int)field8;
                    edx4 += 4;
                    if (eax14 != 0)
                        eax14 += 4;
                    else
                        eax14 = 0;
                    int ecx4 = local20;
                    int edi7 = *(int*)ecx4;
                    if ((*(char(**)(int, int))((*(int*)edi7) + 8))(eax14, edx4)) {
                        sub_4a0230(local50, 1);
                    } else {
                        sub_4a0230(local50, 0);
                        sub_4b3f00((int)field4, (int)&local20, 0, local50);
                    }
                } else {
                    sub_4a0230(local50, 0);
                    sub_4b3f00((int)field4, (int)&local20, 0, local50);
                }
            }
        }

        int edx5 = local38;
        if (edi6 >= *(int*)(edx5 + 8))
            _invalid_parameter_noinfo();
        edi6 += 4;
        local3c = edi6;
    }

    int eax15 = (int)field8;
    if (eax15 != 0)
        eax15 += 4;
    else
        eax15 = 0;
    local2c = eax15;
    local20 = 0x8c149c;
    sub_4b3f00((int)field4, (int)&local2c, 0, local50);
}
