// from server: 39% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int r;
    __try
    {
        r = 1;
    }
    __finally
    {
    }
    return r;
}
