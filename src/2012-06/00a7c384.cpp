// from server: 30% by atomic.potato
extern "C" void __cdecl sub_a814d5(int);

extern "C" int __cdecl imported_QQVW(
    int,
    int,
    int,
    int,
    int,
    float,
    int);

struct S
{
    int f(int, int, int, int, int, float);
};

int S::f(int a, int b, int c, int d, int e, float value)
{
    sub_a814d5(1);
    return imported_QQVW(a, b, c, d, e, value, 0);
}
