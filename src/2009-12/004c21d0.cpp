// from server: 77% by atomic.potato
struct RbxCluster
{
    RbxCluster* get();
};

RbxCluster* RbxCluster::get()
{
    RbxCluster* p = *(RbxCluster**)this;
    while (!*((unsigned char*)*(RbxCluster**)p + 0x5d))
        p = *(RbxCluster**)p;
    return p;
}
