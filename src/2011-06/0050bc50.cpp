// from server: 100% by atomic.potato
struct ServerReplicator
{
    char pad0[155];
    unsigned char f();
};

extern "C" ServerReplicator* __cdecl sub_004de180();

unsigned char ServerReplicator::f()
{
    return sub_004de180()->pad0[155];
}
