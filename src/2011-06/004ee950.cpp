// from server: 100% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

extern "C" void __stdcall f(S *, const S *, double);

extern double g;

S *__stdcall h(S *a, S *b)
{
    f(a, b, g);
    return a;
}
