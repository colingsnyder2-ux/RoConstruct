// from server: 99% by colin
// from server: 87% by king_originala
struct AggChunk {
    char pad[0x28];
};

struct AggContainer {
    void destroy(AggChunk*);
};

#pragma optimize("", off)

void __cdecl cleanup(AggChunk* end, AggChunk* begin,
                     int unused, AggContainer* container)
{
    AggChunk* current;
    unused = unused;
    try {
        for (current = begin; current != end; ++current)
            container->destroy(current);
    }
    catch (...) {
        for (; current != end; ++current)
            container->destroy(current);
        throw;
    }
}

#pragma optimize("", on)
