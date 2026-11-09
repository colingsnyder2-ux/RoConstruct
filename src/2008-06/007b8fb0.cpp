// from server: 100% by king_originala
struct Base {
    virtual void f();
    unsigned char padding[80];
    Base(int, int, int);
};

struct S : Base {
    float value;
    virtual void f();
    S(int, int);
};

S::S(int a, int b) : Base(a, b, 0), value(0.0f)
{
}
