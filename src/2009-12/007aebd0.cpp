// from server: 100% by atomic.potato
struct IndexedMesh
{
    typedef void (__thiscall *Function)(IndexedMesh *);
    Function *vtable;
    IndexedMesh *child;
    int unused8;
    int unusedC;
    int unused10;
    int unused14;
    IndexedMesh *next;
    int unused1C;
    int unused20;

    void f();
};

void IndexedMesh::f()
{
    IndexedMesh *current = this;
    do
    {
        current->vtable[8](current);
        if (current->child != 0)
            current->child->f();
        current = current->next;
    }
    while (current != 0);
}
