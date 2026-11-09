// from server: 65% by atomic.potato
struct IndexedMesh
{
    int value;
    IndexedMesh* parent;
    int result;
};

int __cdecl get(IndexedMesh* p)
{
    int value = p->result;

    while (value == 0)
    {
        p = p->parent;
        if (p == 0)
            return 0;
        value = p->result;
    }

    return value;
}
