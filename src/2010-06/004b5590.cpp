// from server: 56% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void sub_004b2a40(void *);
extern "C" void sub_004b16f0(void *);

void S::f(void *arg)
{
    sub_004b2a40(arg);
    sub_004b16f0(this);
}
