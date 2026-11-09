// from server: 84% by atomic.potato
typedef unsigned int DWORD;

struct S {
    DWORD vtable;
    DWORD pad[9];
    DWORD descriptor;

    int f(int a, int b);
};

extern "C" int __stdcall sub_733010(int *);

int S::f(int a, int b)
{
    DWORD *p = (DWORD *)descriptor;
    DWORD *q = (DWORD *)(*p + 12);
    int value = sub_733010(&b);
    return ((int (__thiscall *)(DWORD *, int, int))(*(DWORD *)q))(p, a, value);
}
