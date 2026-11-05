// from server: 43% by atomic.potato
struct S
{
    int f(int index);
};

int S::f(int index)
{
    return ((int*)this)[index];
}
