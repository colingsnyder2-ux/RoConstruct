// from server: 85% by atomic.potato
struct S
{
    void f(unsigned char);
};

void __stdcall S_f_helper(S *);

void S::f(unsigned char value)
{
    if (*((unsigned char *)this + 0x14) == 0)
        return;
    if (*((unsigned char *)this + 9) != 0)
        return;
    if (value != *((unsigned char *)this + 8))
        return;
    S_f_helper(this);
    *((unsigned char *)this + 0x14) = 0;
}
