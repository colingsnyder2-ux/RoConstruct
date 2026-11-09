// from server: 43% by atomic.potato
struct S {
    char pad[0x48];
    int begin;
    int end;
    int f(int, int, int, int, int, int, int);
};

int S::f(int a, int b, int c, int d, int e, int g, int h)
{
    int n = (end - begin) >> 5;
    return ((int (__stdcall *)(int, int, int, int, int, int, int, int, int))0x500a40)(begin, n, a, b, c, d, e, g, h);
}
