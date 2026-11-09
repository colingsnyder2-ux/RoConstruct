// from server: 36% by atomic.potato
struct S
{
    int (*f)(int, int);
    int a;
    int b;
    int c;

    int invoke();
};

int S::invoke()
{
    return f(a + b, c);
}
