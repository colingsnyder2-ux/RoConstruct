// from server: 85% by atomic.potato
struct S
{
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    int pad5;
    int pad6;
    int vftable;
    int pad7;
    int pad8;

    unsigned char f(int a, int b);
};

struct V
{
    virtual int f(int);
};

unsigned char S::f(int a, int b)
{
    int x = ((V*)vftable)->f(a);
    int y = ((V*)vftable)->f(b);
    return x == y;
}
