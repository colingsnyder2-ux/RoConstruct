// from server: 32% by atomic.potato
struct S {
    char pad0[0x38];
    int __cdecl f(int a, int b);
};

extern "C" int __stdcall sub_b22444(int, int, int, int);
extern "C" int __stdcall sub_b226e8(int, int, int, int, int);
extern "C" void __stdcall sub_b2263c(int);
extern "C" int __cdecl sub_745c30(int, int);

int S::f(int a, int b)
{
    int eax;
    int edi;
    int ebp;
    int ebx;
    int tmp;

    eax = sub_b22444(0, 0xb838f8, 1, 0);
    edi = eax;
    if (edi < 0)
        return 0;

    eax = sub_b22444(edi, 0xb838f4, 1, 0);
    ebp = eax;
    if (ebp < 0)
        return 0;

    eax = eax - edi;
    eax = eax - 1;
    edi = edi + 1;
    sub_b226e8(edi, eax, (int)&tmp, 0, 0);
    tmp = 0;
    ebx = sub_745c30(tmp, b) == 0;
    sub_b2263c((int)&tmp);
    if (ebx)
        return 0;

    ebp = ebp + 1;
    eax = sub_b22444(ebp, 0xb838f8, 1, 0);
    edi = eax;
    if (edi < 0)
        return 0;

    eax = sub_b22444(edi, 0xb838f4, 1, 0);
    if (eax < 0)
        return 0;

    eax = eax - edi;
    eax = eax - 1;
    edi = edi + 1;
    sub_b226e8(edi, eax, (int)&tmp, 0, 0);
    tmp = 1;
    ebx = sub_745c30(tmp, b + 8) == 0;
    sub_b2263c((int)&tmp);
    return ebx == 0;
}
