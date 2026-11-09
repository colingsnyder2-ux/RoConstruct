// from server: 100% by atomic.potato
extern "C" void __stdcall Function007fddb0(void *, void *, double);

double Global00a6f090;

struct S
{
    void *f(void *, void *);
};

void *S::f(void *a, void *b)
{
    Function007fddb0(a, b, Global00a6f090);
    return a;
}
