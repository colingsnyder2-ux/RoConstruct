// from server: 99% by atomic.potato
struct S
{
    char padding[0x120];
    double value;
    char padding2[0x4c];
    int begin;
    int end;
    double f();
};

double S::f()
{
    int n = (end - begin) >> 3;
    double result = (double)n;
    if (n < 0)
        result += 0.0;
    return value / result;
}
