// from server: 49% by atomic.potato
struct S
{
    unsigned int pad[540];
    unsigned int low;
    unsigned int high;
    unsigned int pad2[343];
    unsigned int limitLow;
    unsigned int limitHigh;
    int f(unsigned int, unsigned int);
};

int S::f(unsigned int lowValue, unsigned int highValue)
{
    unsigned int a = lowValue - low;
    unsigned int b = highValue - high;

    if (b < limitHigh)
        return 0;
    if (b > limitHigh)
        return 1;
    if (a <= limitLow)
        return 0;
    return 1;
}
