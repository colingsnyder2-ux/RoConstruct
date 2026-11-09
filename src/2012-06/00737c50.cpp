// from server: 63% by atomic.potato
struct S
{
    int pad[10];

    int __thiscall f(int, int*);
};

extern "C" int __cdecl func_00737b60(int, int*);

int __thiscall S::f(int x, int* y)
{
    int* p = *(int**)((char*)this + 0x28);
    int* q = *(int**)p + 3;
    int a;
    int b = func_00737b60(x, &a);
    return ((int (__thiscall *)(int*, int, int))(*(int**)q))(p, b, (int)y);
}
