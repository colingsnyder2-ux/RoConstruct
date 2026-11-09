// from server: 97% by atomic.potato
typedef int (__thiscall *Fn)(int);

extern "C" int __cdecl sub_007a8bea(int, int, int, int, int);

struct S_func_006499a0
{
    char pad0[76];
    int value;
    int f();
};

int S_func_006499a0::f()
{
    register int result = value;
    result = sub_007a8bea(result, 0, 0xb78e40, 0xb83b6c, 0);
    if (result)
        return (*(Fn *)(*(int *)result + 0x54))(result);
    return 0;
}
