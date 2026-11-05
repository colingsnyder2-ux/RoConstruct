// from server: 91% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

extern "C" void __stdcall f(S *, const S *, double);

double g_value = 0.0;

struct PingJob
{
    int run(S *, const S *);
};

int PingJob::run(S *a, const S *b)
{
    f(a, b, g_value);
    return (int)b;
}
