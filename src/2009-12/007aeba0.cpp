// from server: 46% by atomic.potato
struct IndexedMesh
{
    IndexedMesh *next;
    IndexedMesh *child;
    int value;
};

IndexedMesh * __cdecl f(IndexedMesh *p)
{
    while (p->value == 0)
    {
        p = p->child;
        if (p == 0)
            return 0;
    }
    return p;
}
