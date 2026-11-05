// from server: 53% by atomic.potato
struct S
{
    char pad[8];
    int *object;
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    int (*fn)(int *, int, int, int) =
        (int (*)(int *, int, int, int))(*(int **)object)[1];
    fn(object, 0, b, a);
    return a;
}
