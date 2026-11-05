// from server: 83% by atomic.potato
struct S
{
    int value;
    char data[160];

    void f(void *);
};

extern "C" void sub_402090(void *, void *);
extern "C" void sub_598d90(int, void *);

void S::f(void *arg)
{
    int value = *(int *)arg;
    value = value;
    *(int *)((char *)this + 0x9c) = value;
    sub_402090((char *)this + 0xa0, (char *)arg + 4);
    sub_598d90(*(int *)arg, this);
}
