// from server: 68% by atomic.potato
struct S
{
    int Find(int, int);
    void Update(int);
    int value;
};

int S::Find(int a, int b)
{
    int result = Find(a, b);
    if (result != -1)
    {
        value = result;
        Update(1);
    }
    return result;
}
