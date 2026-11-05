// from server: 59% by atomic.potato
extern "C" int sub_758180(int);

struct S
{
    int f(int);
    int pad[33];
};

unsigned char g_00e31abe;

int S::f(int)
{
    if (g_00e31abe)
        return 0;
    int *p = (int *)((char *)this + 0x84);
    int *q = (int *)((char *)this + 0x84 + *p);
    return sub_758180((int)q);
}
