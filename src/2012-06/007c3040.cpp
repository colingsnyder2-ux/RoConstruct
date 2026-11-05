// from server: 64% by atomic.potato
extern "C" int sub_759160(void *);

extern "C" unsigned char g_flag;

struct S
{
    void *value;
    void *f();
};

void *S::f()
{
    if (g_flag)
        return 0;

    int *p = (int *)value;
    return (void *)sub_759160((char *)this + 0x84 + p[0]);
}
