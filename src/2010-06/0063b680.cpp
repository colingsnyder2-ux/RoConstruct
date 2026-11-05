// from server: 62% by atomic.potato
typedef unsigned int DWORD;

struct S
{
    int f(int, int);
    DWORD m_1c;
};

extern "C" int sub_63abd0(int, int*);

int S::f(int a, int b)
{
    DWORD edi = *(DWORD*)((char*)this + 0x1c);
    DWORD esi = *(DWORD*)edi + 16;
    int value;
    value = sub_63abd0(a, &value);
    return ((int (__thiscall *)(DWORD, int, int))(*(DWORD*)esi))(edi, b, value);
}
