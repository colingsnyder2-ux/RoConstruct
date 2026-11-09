// from server: 75% by atomic.potato
struct S
{
    void f(int *out);
};

void S::f(int *out)
{
    *out = *(int *)((char *)this + 0x46);
}
