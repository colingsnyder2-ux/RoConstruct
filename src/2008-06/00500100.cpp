// from server: 100% by king_originala
struct Pair
{
    short x;
    short y;
};

struct Scalar
{
    float value;
};

struct Data
{
    Pair p;
    Scalar v;
    int n;
};

struct S
{
    char padding[32];
    float value;
    volatile int count;

    void helper(Scalar, int, Pair, int);
    void func_00500100(int);
};

void S::func_00500100(int arg)
{
    Data d;
    d.v.value = value;
    d.n = (count + 1) / 2;
    int c = count;
    d.p.x = (short)c;
    d.p.y = (short)c;
    helper(d.v, d.n, d.p, arg);
}
