// from server: 100% by king_originala
struct Geometry
{
    unsigned char padding[0x38];
    void **connections;
    int count;
    unsigned char padding40[4];
    Geometry **neighbors;
};

void *__cdecl findConnection(Geometry *a, Geometry *b)
{
    Geometry *smaller = a->count < b->count ? a : b;
    Geometry *other = smaller == a ? b : a;

    for (int i = 0; i < smaller->count; ++i)
    {
        if (smaller->neighbors[i] == other)
            return smaller->connections[i];
    }

    return 0;
}
