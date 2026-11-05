// from server: 53% by atomic.potato
struct S {
    char pad[0x48];
    int begin;
    int end;
    int f(int, int, int, int, int, int, int);
};

extern "C" int __stdcall sub_95add0(int, int, int, int, int, int, int, int);

int S::f(int a, int b, int c, int d, int e, int f, int g)
{
    int count = (end - begin) >> 5;
    return sub_95add0(a, b, c, d, e, f, g, count);
}
