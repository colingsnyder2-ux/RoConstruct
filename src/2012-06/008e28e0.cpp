// from server: 61% by atomic.potato
struct S
{
    unsigned char f(void *);
    int *vtable;
    int a;
    int b;
};

unsigned char S::f(void *p)
{
    int x;
    if (p)
        x = (int)((char *)p - 28);
    else
        x = 0;
    return ((unsigned char *)(*(int (**)(void *))(
        *(int **)(x + 132) + *(int *)(x + 16) + *(int *)(this + 12)))(
        (void *)((char *)this + 132 + x)))[0];
}
