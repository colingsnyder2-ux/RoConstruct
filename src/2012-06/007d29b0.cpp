// from server: 90% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    *(int *)this = 0x00bc045c;
    *((int *)this + 1) = 0x00bc0450;
    *((int *)this + 6) = 0x00bc0444;
    *((int *)this + 7) = 0x00bc0438;
    return 0;
}
