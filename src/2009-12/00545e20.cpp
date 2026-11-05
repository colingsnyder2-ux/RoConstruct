// from server: 6% by atomic.potato
struct S
{
    int field_29b0;
    void f();
};

void S::f()
{
    volatile int local_18[6];
    volatile int local_10 = (int)local_18;
    volatile int local_14 = (int)this;
    if (field_29b0 != 0)
        return;
    return;
}
