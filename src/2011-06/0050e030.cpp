// from server: 100% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

void __stdcall f(S *a, const S *b, double c);

struct PacketReceiveJob
{
    char pad[0x1e8];
    double value;
    int g(S *a, S *b);
};

int PacketReceiveJob::g(S *a, S *b)
{
    f(a, b, value);
    return (int)a;
}
