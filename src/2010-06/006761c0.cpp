// from server: 59% by atomic.potato
struct S
{
    int f(int *);
};

extern "C" int __cdecl target(int);

int S::f(int *p)
{
    return target(*(p + 0xf8));
}
