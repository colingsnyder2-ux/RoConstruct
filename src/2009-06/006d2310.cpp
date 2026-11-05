// from server: 100% by atomic.potato
struct IndexedMesh;

struct SubObject
{
    void g(IndexedMesh* m);
};

struct Element
{
    int pad0;
    int pad4;
    int pad8;
    Element** children;
    int count;
    int pad14;
    SubObject* sub;
};

struct IndexedMesh
{
    void f(Element* e);
};

void IndexedMesh::f(Element* e)
{
    SubObject* sub = e->sub;
    if (sub)
    {
        sub->g(this);
        return;
    }

    for (int i = 0; i < e->count; i++)
    {
        f(e->children[i]);
    }
}
