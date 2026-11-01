// from server: 100% by atomic.potato
extern "C" int __stdcall sub_404f70(int, const char *, int, int);

struct S
{
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    return sub_404f70(a, "_][", b, c);
}
