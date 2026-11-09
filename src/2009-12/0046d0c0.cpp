// from server: 34% by atomic.potato
struct S
{
    int f();
    int value[20];
};

int S::f()
{
    while (value[19])
        ;
    return 0;
}
