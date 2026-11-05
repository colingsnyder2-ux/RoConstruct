// from server: 100% by king_originala
extern unsigned char vtable[];

struct S
{
    void* table;
    char padding[0xbc];
    int state;
    float value;

    S* initialize(int a, int b, int c, int d, int kind);
    S* f(int a, int b, int c, int d);
};

S* S::f(int a, int b, int c, int d)
{
    initialize(a, b, c, d, 2);
    value = 0.0f;
    state = 0;
    table = vtable;
    return this;
}
