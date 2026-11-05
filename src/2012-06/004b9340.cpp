// from server: 54% by atomic.potato
struct S
{
    int f(int value);
};

int S::f(int value)
{
    int node = *(int *)this;
    int root = node;

    while (node != 0)
    {
        if (*(int *)(node + 8) == value)
            return node;

        if (node != 0)
            node = *(int *)(node + 4);
        else
            node = root;
    }

    return 0;
}
