// from server: 100% by atomic.potato
struct S {
    unsigned char padding0[4];
    volatile unsigned char enabled;
    unsigned char padding[2356];
    unsigned char value;
    void f();
};

void S::f()
{
    if (enabled)
        value = 0;
}
