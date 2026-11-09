// from server: 81% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

void __stdcall f(S *a, const S *b, double c);

struct Job
{
    char padding[0x1f0];
    double value;
    void g(S *a, S *b);
};

void Job::g(S *a, S *b)
{
    f(a, b, value);
}
