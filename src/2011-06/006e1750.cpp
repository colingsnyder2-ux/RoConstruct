// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    if (*((unsigned char *)this + 4) != 0)
        *((unsigned char *)this + 4) = 0;
}
