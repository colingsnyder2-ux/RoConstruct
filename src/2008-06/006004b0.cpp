// from server: 100% by king_originala
struct S {
    char padding[0x1c8];
    int value;

    void f();
    void g(int);
};

void S::f()
{
    g(value + value % 2 + 1);
}
