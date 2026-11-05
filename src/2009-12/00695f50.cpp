// from server: 84% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    return (*(int (**)(void))(*(int *)this + 8))() + 160;
}
