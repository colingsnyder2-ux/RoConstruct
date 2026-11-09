// from server: 83% by atomic.potato
struct ClientReplicator
{
    void f(int, int, int);
};

extern "C" void __stdcall sub_005a1e30(ClientReplicator *, int, int, int);
extern "C" void __stdcall sub_00577950(ClientReplicator *, int, int, int);

void ClientReplicator::f(int a, int b, int c)
{
    sub_005a1e30(this, c, a, b);
    sub_00577950(this, c, a, b);
}
