// from server: 48% by atomic.potato
extern "C" int __cdecl sub_009ba000(int, int, int, int);

struct S
{
    int f(int, int, int, int, int);
};

int S::f(int a, int b, int c, int d, int e)
{
    return sub_009ba000(a, b, c, d);
}
