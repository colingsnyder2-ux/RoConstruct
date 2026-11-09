// from server: 62% by atomic.potato
struct S
{
    int* p;
    void f(int);
};

extern "C" void sub_008fa3e0(int*);

void S::f(int value)
{
    if (value != 0)
        sub_008fa3e0(p + value - 7);
    else
        sub_008fa3e0(p);
}
