// from server: 100% by king_originala
#pragma optimize("", off)

struct Part {
    char data[16];
    Part(const Part& other);
};

struct S {
    int a;
    int b;
    int c;
    Part part;
    bool enabled;
    bool flag;

    S(int x, int y, int z, const Part& p, bool value);
};

S::S(int x, int y, int z, const Part& p, bool value)
    : a(x), b(y), c(z), part(p), enabled(value), flag(false)
{
}
