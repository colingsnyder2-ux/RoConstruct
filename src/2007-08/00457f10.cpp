// from server: 100% by colin
struct Sub {
    void method(int);
};

struct S {
    char pad[0xe8];
    Sub sub;
    int f(int);
};

int S::f(int a)
{
    sub.method(a);
    return a;
}
