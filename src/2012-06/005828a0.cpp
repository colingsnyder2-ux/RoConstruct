// from server: 71% by atomic.potato
extern "C" void __cdecl G1_func_009779e0(double, void *);

struct S
{
    void *func(void *, void *);
};

void *S::func(void *a, void *b)
{
    double value;
    G1_func_009779e0(value, b);
    return b;
}
