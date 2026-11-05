// from server: 75% by atomic.potato
struct S
{
    int value;
    void update(int);
};

extern void G1_func_00414500(int, int);

void S::update(int value)
{
    if (value != *(int *)((char *)this + 0x9c))
    {
        *(int *)((char *)this + 0x9c) = value;
        G1_func_00414500(value, *(int *)((char *)this + 0x144));
    }
}
