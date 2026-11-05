// from server: 97% by atomic.potato
struct S
{
    char padding[388];
    int begin;
    int end;
    double value;

    double f();
};

double S::f()
{
    int count = (end - begin) >> 3;
    double result = (double)count;
    if (count < 0)
        result += 4503599627370496.0;
    return value / result;
}
