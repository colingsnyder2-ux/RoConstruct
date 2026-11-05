// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (*((unsigned char *)this + 4))
        return 1;
    return *((unsigned char *)this + 5) != 0 ? -1 : 0;
}
