// from server: 35% by atomic.potato
struct S
{
    int f();
};

extern "C" void sub_8ec4b0(void *, void *, unsigned char);

int S::f()
{
    void *p = 0;
    unsigned char b = 0;
    sub_8ec4b0(this, p, b);
    return (int)this;
}
