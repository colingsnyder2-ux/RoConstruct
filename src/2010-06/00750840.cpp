// from server: 100% by atomic.potato
struct Sub
{
    void method(int x);
};

struct ArgNode
{
    char pad0[0xc];
    ArgNode** array;
    int count;
    char pad1[4];
    Sub* sub;
};

struct IndexedMesh
{
    void f(ArgNode* arg);
};

void IndexedMesh::f(ArgNode* arg)
{
    if (arg->sub)
    {
        arg->sub->method(0);
        return;
    }

    for (int i = 0; i < arg->count; i++)
        f(arg->array[i]);
}
