// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_edgeremovenativeb7da9cbb3ce5d29e.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>

#include <intrin.h>

struct Edge {
    char padding[12];
    void* owner;
    int reserved;
    int firstIndex;
    int secondIndex;
};

typedef G3D::Array<Edge*> EdgeArray;
typedef G3D::Array<void*> ValueArray;

struct Primitive {
    void* owner;
    EdgeArray edges;
    ValueArray values;

    void remove(Edge* edge);
};

void Primitive::remove(Edge* edge)
{
    int index;
    if (owner == edge->owner)
        index = edge->firstIndex;
    else
        index = edge->secondIndex;

    Edge* lastEdge = edges.last();
    void* lastValue = values.last();

    edges[index] = lastEdge;
    values[index] = lastValue;

    edges.popDiscard();
    values.popDiscard();

    if (owner == lastEdge->owner)
        lastEdge->firstIndex = index;
    else
        lastEdge->secondIndex = index;

    if (owner == edge->owner)
        edge->firstIndex = -1;
    else
        edge->secondIndex = -1;
}