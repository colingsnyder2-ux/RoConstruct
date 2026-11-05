// from server: 88% by atomic.potato
extern "C" void __stdcall sub_4ea4b0(int, int);

struct ServerReplicator {
    unsigned char padding[0x266d];
    unsigned char field_266d;
    void f();
};

void ServerReplicator::f()
{
    sub_4ea4b0(0, field_266d);
}
