// from server: 51% by atomic.potato
struct S
{
    int f(int **p);
};

int S::f(int **p)
{
    return (*p)[0];
}
