// from server: 76% by atomic.potato
struct RBX_Network_Replicator {
    int f();
};

int RBX_Network_Replicator::f()
{
    int v1 = *(int*)this;
    return *(int*)(v1 + 0x5c);
}
