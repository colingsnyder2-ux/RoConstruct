// from server: 21% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int value = 0;
    int unused = 0;
    return unused;
}
