// from server: 41% by atomic.potato
struct S
{
    int value;
    int first;
    int second;
    S(int, int);
};

S::S(int a, int b)
{
    value = 0;
    first = a;
    second = b;
}
