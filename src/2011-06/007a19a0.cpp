// from server: 43% by atomic.potato
struct IndexedMesh
{
    IndexedMesh* next;
    int value;
    int reserved1;
    int reserved2;
    int state;
    IndexedMesh* parent;
};

IndexedMesh* __cdecl get(IndexedMesh* p)
{
    if (p->state != 0)
        return p;

    for (;;)
    {
        p = p->parent;
        if (p != 0)
            return 0;

        if (p->state != 0)
            return p;
    }
}
