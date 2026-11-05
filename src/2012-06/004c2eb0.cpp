// from server: 21% by atomic.potato
struct S
{
    int *vtable;
    int *object;
    int value;
    int count;

    void f(int a, int b);
};

void S::f(int a, int b)
{
    object->operator int()(a, b);
    count += 3;
}
