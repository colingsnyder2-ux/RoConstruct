// from server: 51% by atomic.potato
struct S
{
    int value;
    char flag;
    S(int);
};

S::S(int v)
{
    value = v;
    flag = 0;
}
