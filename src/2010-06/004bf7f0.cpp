// from server: 52% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    if (*(int*)this == 0)
        return;
    f();
}
