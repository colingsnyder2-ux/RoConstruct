// from server: 68% by atomic.potato
typedef unsigned int DWORD;

struct S
{
    int a;
    int b;
    int c;
    int d;
    int f(int, int);
};

extern "C" int sub_006cc860(S *, void *);

int S::f(int x, int y)
{
    sub_006cc860((S *)((char *)this + 0x34), &x);
    sub_006cc860((S *)((char *)this + 0x40), &y);
    return 0;
}
