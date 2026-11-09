// from server: 59% by atomic.potato
extern "C" void target758110(void *);

struct S
{
    int f();
    void *field84;
};

unsigned char global_flag;

int S::f()
{
    if (global_flag)
        return 0;

    void *p = field84;
    unsigned int v = *(unsigned int *)p;
    target758110((char *)this + 132 + v);
    return 0;
}
