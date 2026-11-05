// from server: 78% by atomic.potato
extern "C" void sub_485230(void *);

struct S
{
    void *f(void *);
};

void *S::f(void *arg)
{
    sub_485230(arg);
    return arg;
}
