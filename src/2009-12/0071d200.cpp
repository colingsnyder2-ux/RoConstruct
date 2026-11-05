// from server: 72% by atomic.potato
struct VDataModelMesh
{
    int get();
};

int VDataModelMesh::get()
{
    int index = *(int *)((char *)this + 4);
    int **object = *(int ***)this;
    int *table = *(int **)((char *)object + 0x168);
    int *entry = (int *)((char *)table + index * 4 + 0x124);
    int result = *entry;
    if (result == 0)
    {
        static int fallback;
        static int init;
        if ((init & 1) == 0)
        {
            init |= 1;
            *(float *)0xb93fd0 = *(float *)0x9b2364;
            *(float *)0xb93fd4 = *(float *)0x9af2dc;
            *(int *)0xb93fcc = 0;
        }
        result = (int)&fallback;
    }
    return *(int *)result;
}
