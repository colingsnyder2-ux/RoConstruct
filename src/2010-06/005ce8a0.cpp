// from server: 55% by atomic.potato
struct S
{
    int f();
    char pad[0x808];
    int value;
};

extern "C" void sub_5cce60(void *);

double g_5;
int S::f()
{
    sub_5cce60((char *)this + 8);
    return (double)value * g_5;
}
