// from server: 50% by atomic.potato
struct PartChunk
{
    int *vtable;
    int field_dc;
    void *f(void *, void *, void *, int);
};

void *PartChunk::f(void *a, void *b, void *c, int d)
{
    void *result;
    result = ((void *(__thiscall *)(void *, void *, int, int))vtable[12])(a, (void *)field_dc, d, 0);
    return d ? (void *)d : result;
}
