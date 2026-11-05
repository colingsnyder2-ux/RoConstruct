// from server: 80% by atomic.potato
struct S {
    int a;
    int b;
    int c;
    int f(int, int);
};

extern "C" int __stdcall sub_770780(int, int, int);

int S::f(int x, int y)
{
    return sub_770780(c, x, y);
}
