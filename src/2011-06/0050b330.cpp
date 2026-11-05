// from server: 84% by atomic.potato
struct ServerReplicator
{
    char pad0[0x1d1c];
    unsigned char f();
};

extern "C" unsigned char __fastcall sub_004fa3f0(ServerReplicator*);

unsigned char ServerReplicator::f()
{
    if (!sub_004fa3f0(this))
        return 0;
    if (!pad0[0x1d1c])
        return 0;
    return sub_004fa3f0(this);
}
