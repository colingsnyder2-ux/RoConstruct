// from server: 88% by atomic.potato
extern "C" void sub_004c83e0(void *, void *);

struct EventDesc
{
    void *filler0[12];
    int base;
    int index;
    void f(void *);
};

void EventDesc::f(void *arg)
{
    char *p = (char *)arg;
    if (p)
        p -= 28;
    else
        p = 0;

    int value = *(int *)(*(int *)(p + 132) + index) + base;
    sub_004c83e0(this, p + value + 132);
}
