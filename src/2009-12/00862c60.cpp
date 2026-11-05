// from server: 100% by atomic.potato
struct S
{
    int f(int, int);
};

extern "C" int __stdcall Target(int);

int S::f(int, int value)
{
    Target(value);
    return 0;
}
