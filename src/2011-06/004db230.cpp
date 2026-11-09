// from server: 65% by atomic.potato
struct Sub {
    void init(int);
};

struct S {
    char pad0[4];
    Sub sub;
    int f(int a1, int a2);
    int g(int a1, int a2);
};

int S::f(int a1, int a2)
{
    int local = 0;
    sub.init(1);
    g(a1, a2);
    return a1;
}
