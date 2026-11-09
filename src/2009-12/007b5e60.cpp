// from server: 100% by atomic.potato
struct V
{
    virtual bool g();
    virtual bool h();
    virtual bool i();
    virtual bool j();
};

struct S
{
    bool f();
};

bool S::f()
{
    int i = 0;
    while (i < *(int*)((char*)this + 0xcc))
    {
        V* p = *(V**)((char*)this + 0xbc + i * 4);
        if (p->j())
            return true;
        ++i;
    }
    return false;
}
