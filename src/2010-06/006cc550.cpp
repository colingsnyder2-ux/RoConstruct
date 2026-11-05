// from server: 45% by atomic.potato
typedef unsigned int DWORD;

extern "C" DWORD __cdecl sub_6cc410(DWORD);

struct S
{
    DWORD f(DWORD, DWORD);
};

DWORD S::f(DWORD a, DWORD b)
{
    DWORD obj = *(DWORD *)((char *)this + 0x1c);
    DWORD vtable = *(DWORD *)obj;
    DWORD key = sub_6cc410(b);
    return ((DWORD (__thiscall *)(DWORD, DWORD, DWORD))(*(DWORD *)(vtable + 0x10)))(obj, a, key);
}
