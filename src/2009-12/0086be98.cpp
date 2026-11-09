// from server: 48% by atomic.potato
struct S
{
    int f(int, int, int, int, int, int, int, int);
};

int S::f(int, int, int, int, int, int, int, int)
{
    return (int)0x80004005;
}
