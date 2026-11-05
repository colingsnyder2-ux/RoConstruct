// from server: 66% by atomic.potato
struct S
{
    void f(int, int, int, int);
};

extern "C" void target();

void S::f(int a, int b, int c, int d)
{
    target();
}
