// from server: 37% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int value)
{
    int (*p)(int *, int) = 0;
    return p((int *)this + 0x26, *(int *)((char *)this + 0x9c));
}
