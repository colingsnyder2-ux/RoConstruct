// from server: 31% by atomic.potato
struct S_func_00753c00
{
    int f();
};

struct S_func_007544c0
{
    char pad0[0];
    int f(int);
};

int S_func_00753c00::f()
{
    return 0;
}

int S_func_007544c0::f(int value)
{
    return ((S_func_00753c00*)(((char*)this) - 816))->f();
}
