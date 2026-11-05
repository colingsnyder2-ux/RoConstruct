// from server: 81% by atomic.potato
struct S
{
    void f(int);
};

void sub_72d780(S *);

void S::f(int)
{
    ++((int *)this)[0x94 / 4];
    if (((int *)this)[0x94 / 4] >= ((int *)this)[0x74 / 4])
    {
        ((int *)this)[0x78 / 4] = 0;
        sub_72d780(this);
    }
}
