// from server: 100% by atomic.potato
struct S
{
    int Match(int **a, int *b);
};

int S::Match(int **a, int *b)
{
    int *p = *a;
    while (p != 0)
    {
        if (b[0] == p[-10] && b[1] == p[-9] && b[2] == p[-8])
            break;
        p = (int *)*p;
    }
    return (int)p;
}
