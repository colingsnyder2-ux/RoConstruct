// from server: 100% by king_originala
struct Part {
    void update();
};

struct S {
    unsigned char padding[0xa8];
    Part part;
    void prepare();
    int f();
};

int S::f()
{
    prepare();
    part.update();
    return 0;
}
