// from server: 47% by atomic.potato
struct S
{
    void f();
};

extern "C" void sub_7044c0(void *, void *, int);

void S::f()
{
    int *p = *(int **)0;
    int x = 0;
    sub_7044c0((void *)(p + 2), &x, 0);
}
