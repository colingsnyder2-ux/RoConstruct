// from server: 92% by atomic.potato
extern "C" void __stdcall sub_004f92b0(int, int);

struct ServerReplicator_0050b310
{
    char pad0[6600];
    unsigned char field_19c8;
    char pad1[851];
    unsigned char field_1d1c;
    void f();
};

void ServerReplicator_0050b310::f()
{
    sub_004f92b0(0, field_19c8);
    field_1d1c = 0;
}
