// from server: 75% by atomic.potato
typedef unsigned int DWORD;

extern "C" DWORD sub_63acb0(DWORD, DWORD *);

struct S
{
    DWORD pad[7];
    DWORD member_1c;
    DWORD f(DWORD, DWORD);
};

DWORD S::f(DWORD a, DWORD b)
{
    DWORD edi = member_1c;
    DWORD esi = *(DWORD *)edi + 0x10;
    DWORD eax = sub_63acb0(b, &b);
    DWORD (*fn)(DWORD, DWORD) = *(DWORD (**)(DWORD, DWORD))esi;
    return fn(edi, eax);
}
