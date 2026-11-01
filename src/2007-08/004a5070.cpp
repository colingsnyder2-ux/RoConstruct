// from server: 100% by colin
struct S
{
    int* ptr;
    int value;
    void f();
};

void S::f()
{
    *ptr = value;
}
