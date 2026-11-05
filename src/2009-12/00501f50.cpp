// from server: 58% by atomic.potato
struct S
{
    int f(int);
};

void g(S*, int);

int S::f(int value)
{
    g(this, value);
    return value;
}
