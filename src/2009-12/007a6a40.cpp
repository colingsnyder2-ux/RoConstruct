// from server: 50% by atomic.potato
struct S
{
    struct T
    {
        int value;
    };

    T* field;
    int f();
};

int S::f()
{
    T* p = field;
    if (p)
        return p->value;
    return 0;
}
