// from server: 100% by atomic.potato
struct ClientReplicator
{
    void f(double value, int a, int b);
};

void ClientReplicator::f(double value, int a, int b)
{
    *(double*)((char*)this + 0x12f8) = value;
    *(int*)((char*)this + 0x1300) = a;
    *(int*)((char*)this + 0x1304) = b;
}
