// from server: 15% by atomic.potato
struct RootInstance
{
    void f();
};

struct S
{
    void f(RootInstance* first, RootInstance* last);
};

void RootInstance::f()
{
}

void S::f(RootInstance* first, RootInstance* last)
{
    while (first != last)
    {
        first->f();
        first = (RootInstance*)((char*)first + 0x18);
    }
}
