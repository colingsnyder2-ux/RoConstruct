// from server: 84% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct V
    {
        int (**table)();
    };

    V* p = *(V**)((char*)this + 0xf0);
    return p->table[4]();
}
