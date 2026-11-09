// from server: 79% by atomic.potato
struct S_func_006cf710
{
    int f(int a1, int a2);
};

extern "C" int __cdecl sub_006ced10(int*);

int S_func_006cf710::f(int a1, int a2)
{
    int* edi = *(int**)((char*)this + 0x1c);
    int* esi = (int*)(*edi + 0x10);
    int value = sub_006ced10(&a2);
    return ((int (__thiscall *)(int*, int, int))(*esi))(edi, a1, value);
}
