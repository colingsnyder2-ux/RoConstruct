// from server: 89% by atomic.potato
extern "C" void destroy_ifstream(void *);

struct S {
    int f(int);
};

int S::f(int flag)
{
    S *p = (S *)((char *)this - 0x58);
    destroy_ifstream(p);
    if (flag & 1)
        destroy_ifstream(p);
    return (int)p;
}
