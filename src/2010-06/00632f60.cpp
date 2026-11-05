// from server: 87% by atomic.potato
struct S
{
    float f(int *p);
};

float S::f(int *p)
{
    if (p)
        return *(float *)((char *)p + *(int *)((char *)this + 8) - 28);
    return *(float *)((char *)0 + *(int *)((char *)this + 8));
}
