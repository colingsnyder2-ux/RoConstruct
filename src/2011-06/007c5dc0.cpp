// from server: 100% by atomic.potato
struct S_func_007c5dc0
{
    int f(int);
};

int S_func_007c5dc0::f(int a)
{
    if (a == 0)
        return *(int*)((char*)this + 0x18);
    return *(int*)((char*)this + 0x1c);
}
