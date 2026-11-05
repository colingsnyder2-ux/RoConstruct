// from server: 27% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int value)
{
    return 0xA88378 + (value - 1) * 12;
}
