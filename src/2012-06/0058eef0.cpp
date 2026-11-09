// from server: 87% by atomic.potato
struct S
{
    double value;
    int f(int, int);
};

extern "C" int __cdecl helper(int, int, double);

int S::f(int a, int b)
{
    helper(a, b, *(double *)((char *)this + 0x220));
    return b;
}
