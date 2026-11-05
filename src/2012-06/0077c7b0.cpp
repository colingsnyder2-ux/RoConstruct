// from server: 90% by atomic.potato
struct S
{
    int f();
};

S *g;

int S::f()
{
    *(int *)this = 0x00bb0a94;
    *((int *)this + 1) = 0x00bb0a88;
    *((int *)this + 6) = 0x00bb0a7c;
    *((int *)this + 7) = 0x00bb0a70;
    return 0;
}
