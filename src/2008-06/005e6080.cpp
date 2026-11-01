// from server: 100% by king_originala
struct Geometry;
struct Edge;
typedef Edge Primitive;

struct State {
    char pad[0x14];
    State* related;
};

struct Geometry {
    char pad[0xa0];
    State* state;

    Primitive* getFirstB();
    Edge* getNextB(Edge*);
};

struct Edge {
    char pad0[0x0c];
    Geometry* g0;
    Geometry* g1;
    char pad1[0x10];
    unsigned char enabled;
};

Edge* __cdecl findEdge(Geometry* geometry)
{
    Edge* edge = geometry->getFirstB();
    while (edge) {
        if (edge->enabled) {
            Geometry* other = edge->g0;
            if (geometry == other)
                other = edge->g1;
            if (!other || geometry->state->related == other->state)
                return edge;
        }
        edge = geometry->getNextB(edge);
    }
    return 0;
}
