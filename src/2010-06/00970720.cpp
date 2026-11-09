// from server: 75% by atomic.potato
struct S
{
    int f(int, const float *);
};

int S::f(int value, const float *p)
{
    if (value == 0 && p[1] > p[0])
        return 1;
    return 0;
}
