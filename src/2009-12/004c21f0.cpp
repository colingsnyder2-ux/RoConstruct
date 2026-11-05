// from server: 51% by atomic.potato
struct RbxCluster
{
    RbxCluster* parent;
    RbxCluster* get();
};

RbxCluster* RbxCluster::get()
{
    RbxCluster* p = parent;
    while (!p->parent->parent)
        p = p->parent;
    return p;
}
