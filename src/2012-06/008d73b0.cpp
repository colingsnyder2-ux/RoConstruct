// from server: 78% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __stdcall sub_8d72d0(DWORD, DWORD*);

struct S
{
    DWORD field28;
    DWORD f(DWORD, DWORD);
};

DWORD S::f(DWORD a, DWORD b)
{
    DWORD* p = reinterpret_cast<DWORD*>(field28);
    DWORD* q = reinterpret_cast<DWORD*>(*p + 12);
    DWORD t = sub_8d72d0(b, &b);
    return reinterpret_cast<DWORD (__thiscall *)(DWORD*, DWORD, DWORD)>(*q)(p, a, t);
}
