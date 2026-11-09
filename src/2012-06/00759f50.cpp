// from server: 82% by atomic.potato
extern "C" void sub_759de0(void *, double, const char *);

struct EventDesc
{
    void f(int *);
};

double g_0xb4fd78;

void EventDesc::f(int *p)
{
    int value = *p;
    double x = (double)value;
    if (value < 0)
        x += g_0xb4fd78;
    sub_759de0(this, x, (const char *)0xb50d9c);
}
