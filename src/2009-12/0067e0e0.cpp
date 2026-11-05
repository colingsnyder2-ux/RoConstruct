// from server: 71% by atomic.potato
extern "C" void sub_636a50(void *, void *);
extern "C" void sub_9189c0(void *);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    sub_636a50(this, arg);
    *(int *)((char *)this + 0xcc) = 0;
    sub_9189c0((char *)this + 0xa4);
}
