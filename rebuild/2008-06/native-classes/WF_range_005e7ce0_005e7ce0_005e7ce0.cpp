// native-flags: __cdecl; returns void*; leaf; 74 bytes; 005e7ce0-005e7d29; optimized (/O2)
// Stand-in for RBX::Geometry layout: connections@0x38, count@0x3c, neighbors@0x44.
// The real class header was not provided, so the struct below mirrors the analog.

#pragma optimize("gty", on)

struct Geometry
{
    unsigned char padding[0x38];
    void **connections;
    int count;
    unsigned char padding40[4];
    Geometry **neighbors;
};

void *__cdecl sub_005e7ce0(Geometry *a, Geometry *b)
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
