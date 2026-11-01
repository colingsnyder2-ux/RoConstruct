// from server: 100% by king_originala
#pragma optimize("", off)

struct Part {
    int data[2];
    Part(int value);
};

struct S {
    int a;
    int b;
    int c;
    Part part;
    unsigned char flag;
    unsigned char zero;

    S(int x, int y, int z, int value, unsigned char enabled);
};

S::S(int x, int y, int z, int value, unsigned char enabled)
    : a(x), b(y), c(z), part(value), flag(enabled), zero(0)
{
}
