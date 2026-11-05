// from server: 70% by atomic.potato
struct S {
    int value;
    void f(int *);
};

void S::f(int *p)
{
    int v = *p;
    if (v != *(int *)((char *)this + 0xa4)) {
        *(int *)((char *)this + 0xa4) = v;
        *(int *)((char *)p + 0) = 0xb7ff18;
        return;
    }
}
