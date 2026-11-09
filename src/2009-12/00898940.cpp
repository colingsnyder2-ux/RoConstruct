// from server: 100% by atomic.potato
struct Elem
{
    int check(int a);
};

struct S
{
    int count();
    Elem* get(int i);
    int find(int a);
};

int S::find(int a)
{
    for (int i = 0; i < count(); ++i)
    {
        Elem* e = get(i);
        int r = e->check(a);
        if (r != 0)
            return r;
    }
    return 0;
}
