// from server: 62% by atomic.potato
extern "C" int CallOne(int, int, int);
extern "C" int CallTwo(int, int);

struct S
{
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    int v = CallOne(b, c, a);
    v = CallTwo(b, v);
    return (**(int (**)(S *, int))(*(int **)this + 0x70))(this, v);
}
