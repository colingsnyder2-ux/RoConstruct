// from server: 49% by atomic.potato
struct S;

extern "C" void __stdcall sub_0069b490(S *, int, int, int);

struct S
{
    int f();
    int pad0[36];
    int a;
    int b;
    int c;
    int d;
};

int S::f()
{
    sub_0069b490((S *)((char *)this + 156), a, b, c);
    return 0;
}
