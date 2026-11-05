// from server: 100% by atomic.potato
struct HandlesBase
{
    void f(int, int);
};

void HandlesBase::f(int a, int b)
{
    *(int*)((char*)this + 0xf4) = a;
    *(int*)((char*)this + 0xf8) = b;
}
