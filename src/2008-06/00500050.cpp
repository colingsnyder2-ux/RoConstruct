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
};

struct S
{
    char padding[32];
    float value;
    int count;

    void helper(Scalar, Pair, int);
    void func_00500050(int);
};

void S::func_00500050(int arg)
{
    Data d;
    d.v.value = value;
    int c = count;
    d.p.x = (short)c;
    d.p.y = (short)c;
    helper(d.v, d.p, arg);
}
