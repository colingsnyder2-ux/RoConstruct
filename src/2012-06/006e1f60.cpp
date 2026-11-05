// from server: 73% by atomic.potato
extern "C" void __stdcall sub_6df6c0(int, int, int, int, int, int);

struct S {
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    char tmp = 0;
    sub_6df6c0(a, b, c, *(int*)&tmp, c, b);
    return b * 100 + a;
}
