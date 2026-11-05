// from server: 51% by atomic.potato
struct Callee
{
    void method(int);
};

struct EventDesc
{
    void f(int, int);
};

void EventDesc::f(int a, int b)
{
    if (a)
    {
        ((Callee *)((char *)*(unsigned int *)((char *)this + 0x24) + (a - 0x1c)))->method(b);
    }
    else
    {
        ((Callee *)(*(unsigned int *)((char *)this + 0x24)))->method(b);
    }
}
