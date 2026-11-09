// from server: 73% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int x)
{
    return (*(int (**)(void))(*(int **)((*(int **)((char *)x - 0xcc)) + 0x20)))();
}
