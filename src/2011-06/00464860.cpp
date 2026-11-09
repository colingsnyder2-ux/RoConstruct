// from server: 100% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

extern "C" void __stdcall f(S *, const S *, double);

struct UserInputJob
{
    S *Render(S *, S *);
};

double g_value = 0.0;

S *UserInputJob::Render(S *a, S *b)
{
    f(a, b, g_value);
    return a;
}
