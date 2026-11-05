// from server: 45% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

extern S *get_value(S *);
extern void __stdcall f(S *, const S *, double);

struct PacketReceiveJob
{
    int process(S *, int);
};

int PacketReceiveJob::process(S *b, int a)
{
    S *p = get_value((S *)this);
    f((S *)this, b, p->value);
    return a;
}
