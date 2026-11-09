// from server: 82% by atomic.potato
struct S
{
    void f();
};

extern int g_98c060;

void S::f()
{
    int *p = (int *)((char *)this + 4);
    *(int *)this = 0x9b3e9c;
    if (p)
        *p = (int)((char *)p - 4);
    else
        *p = 0;
    *(int *)this = g_98c060;
}
