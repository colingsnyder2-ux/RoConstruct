// from server: 56% by atomic.potato
struct S_func_00666ae0
{
    bool initialized;
    void f(void *, void *);
};

void S_func_00666ae0::f(void *a1, void *a2)
{
    if (!initialized)
    {
        ((unsigned int *)a1)[0] = 0;
        ((unsigned int *)a1)[1] = 0;
        ((unsigned int *)a1)[2] = 0;
        ((unsigned int *)a1)[3] = 0;
        return;
    }

    f(a1, a2);
}
