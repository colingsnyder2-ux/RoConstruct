// from server: 100% by colin
// from server: 95% by atomic.potato
struct S
{
    void f(int* p, int dummy);
};

void S::f(int* p, int dummy)
{
    p[0] = 0x124;
    p[1] = 0x24;
}