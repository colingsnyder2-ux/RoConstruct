// from server: 79% by atomic.potato
extern "C" int __stdcall sub_007fddb0(double, int, int);

struct PacketReceiveJob
{
    double value;
    int receive(int, int);
};

int PacketReceiveJob::receive(int a, int b)
{
    sub_007fddb0(*(double*)((char*)this + 0x1e8), a, b);
    return b;
}
