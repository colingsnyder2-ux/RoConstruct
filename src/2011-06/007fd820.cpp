// from server: 100% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

void __stdcall f(S *a, const S *b, double c);

void __stdcall f(S *a, const S *b, double c)
{
    a->value = b->value * c;
    a->state = 0;
}
