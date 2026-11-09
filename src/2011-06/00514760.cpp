// from server: 62% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" int g(void *);
extern "C" int h(int);

int S::f(void *p)
{
    return g((void *)h(*(int *)((char *)p + 0x168)));
}
