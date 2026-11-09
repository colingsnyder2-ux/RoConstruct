// from server: 79% by atomic.potato
struct S
{
    int a;
    char padding[256];
    double b;
};

extern "C" S* f1(S*);
extern "C" void f2(S*, int, int, double);

struct PacketReceiveJob
{
    int receive(int, int);
};

int PacketReceiveJob::receive(int a, int b)
{
    S* p = f1((S*)this);
    f2((S*)this, b, a, p->b);
    return b;
}
