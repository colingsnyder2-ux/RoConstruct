// from server: 100% by atomic.potato
struct S
{
    int a(int, int);
    int b(int);
};

struct T : S
{
    int f(int);
};

int T::f(int value)
{
    int result = a(value, 0);
    return b(result);
}
