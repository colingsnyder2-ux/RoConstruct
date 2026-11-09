// from server: 57% by atomic.potato
extern "C" void sub_00666300(void *);

struct S
{
    int pad0;
    int pad1;
    int value;
    double f();
};

double S::f()
{
    char *p = (char *)this + 8;
    sub_00666300(p);
    return (double)(*(int *)(p + 0x808)) * 1.0;
}
