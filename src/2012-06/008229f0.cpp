// from server: 58% by atomic.potato
extern "C" int __cdecl call_67f5b0(int, int *);
extern "C" int call_76beb0(void *, int);

struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    int x;
    int y = call_67f5b0(b, &x);
    return call_76beb0(this, y);
}
