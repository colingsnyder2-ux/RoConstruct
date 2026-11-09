// from server: 84% by atomic.potato
struct S
{
    int value;
    void set(int);
};

extern void G1_func_0040c470();

void S::set(int value)
{
    if (value < 0)
        value = 1;
    if (value != *(int *)((char *)this + 0x168))
    {
        *(int *)((char *)this + 0x168) = value;
        G1_func_0040c470();
    }
}
