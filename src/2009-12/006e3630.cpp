// from server: 42% by atomic.potato
struct S
{
    bool f(int);
    void g(int);
    bool h(int);
};

bool S::f(int value)
{
    return h(value);
}

void S::g(int value)
{
    if (!f(value))
    {
        h(value);
        *(int *)((char *)this + 0x1f8) = 0;
    }
}

bool S::h(int)
{
    return false;
}
