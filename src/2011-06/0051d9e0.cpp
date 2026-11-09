// from server: 58% by atomic.potato
struct S
{
    int value;
    int f(int);
    int pad0[18];
    int limit;
    int pad1[1];
    double total;
};

double g_00a66290;

int S::f(int value)
{
    if (value > limit)
        limit = value;
    ++value;
    double x = (double)(value - 1);
    if (value - 1 < 0)
        x += g_00a66290;
    total += x;
    return 0;
}
