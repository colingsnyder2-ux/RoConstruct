// from server: 41% by atomic.potato
extern "C" int Target(void *);

volatile unsigned char g_flag;

struct S
{
    void *field_84;
    int f();
};

int S::f()
{
    if (g_flag)
        return 0;

    void *p = field_84;
    return Target((char *)((int)p + *(int *)p + (int)this + 132));
}
