// from server: 89% by atomic.potato
extern "C" void sub_80A058(void *);
extern "C" void sub_A403C4(void *);

struct S {
    int f(int);
};

int S::f(int value)
{
    char *p = (char *)this - 0x58;
    sub_A403C4(p);
    if (value & 1)
        sub_80A058(p);
    return (int)p;
}
