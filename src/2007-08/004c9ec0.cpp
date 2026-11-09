// from server: 100% by colin
struct S {
    int f();
    int a;
    int b;
    int c;
};

int S::f()
{
    c = 0;
    a = 0;
    b = 0;
    return (int)this;
}
