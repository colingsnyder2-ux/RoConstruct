// from server: 33% by atomic.potato
struct Sub {
    void init(int);
};

struct S_func_0062fe20 {
    char pad0[4];
    Sub sub;
    int f(int, int);
};

int S_func_0062fe20::f(int a, int b)
{
    sub.init(1);
    return a;
}
