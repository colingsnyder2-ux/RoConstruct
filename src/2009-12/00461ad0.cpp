// from server: 69% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void sub_5f1f50(void *, void *);

void S::f(void *arg)
{
    sub_5f1f50((char *)this + 0xa0, arg);
}
