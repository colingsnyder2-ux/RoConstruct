// from server: 15% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* p = (int*)this + 2;
    return (int)p;
}
