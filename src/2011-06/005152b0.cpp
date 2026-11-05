// from server: 100% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

void __stdcall f(S *a, const S *b, double c);

struct NetworkOwnerJob
{
    float value;
    S *method(S *, S *);
};

S *NetworkOwnerJob::method(S *a, S *b)
{
    f(a, b, (double)*(float *)((char *)this + 0x1e8));
    return a;
}
