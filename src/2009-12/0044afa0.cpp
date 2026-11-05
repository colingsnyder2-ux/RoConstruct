// from server: 60% by atomic.potato
struct S_func_0044afa0
{
    struct Base
    {
        virtual void f(int, int);
    };

    Base* base;
    int value;
    int f(int);
};

int S_func_0044afa0::f(int value)
{
    base->f(0, this->value);
    return value;
}
