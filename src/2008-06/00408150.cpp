// from server: 100% by king_originala
struct S {
    int g(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

extern "C" int __stdcall f(
    void *,
    unsigned int a,
    unsigned int b,
    unsigned int c,
    unsigned int d,
    unsigned int e)
{
    return reinterpret_cast<S *>(0x928bd8)->g(a, b, c, d, e);
}
