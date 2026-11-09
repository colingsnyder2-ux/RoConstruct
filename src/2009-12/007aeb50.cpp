// from server: 100% by atomic.potato
struct S_func_007aeb50
{
    static char f(void *);
};

char S_func_007aeb50::f(void *p)
{
    if (p != 0 && *(int *)((char *)p + 0x18) != 0)
        return 1;
    return 0;
}
