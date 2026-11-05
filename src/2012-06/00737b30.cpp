// from server: 39% by atomic.potato
struct S
{
    int f(int);
    int g(int *);
};

int S::f(int value)
{
    return value + 4;
}

int S::g(int *value)
{
    return *value;
}

struct T : S
{
    int h(int);
};

int T::h(int value)
{
    int temporary = f(value);
    return g(&temporary);
}
