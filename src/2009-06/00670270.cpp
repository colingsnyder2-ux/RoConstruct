// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Edge;
struct Primitive {
    char pad[0xa4];
    Edge** edges;
    int numEdges;
    Edge* next(Edge* e);
    Edge* resolve(Edge* e);
    Edge* getEdge(int i) const { return (i < numEdges) ? edges[i] : 0; }
};
struct Edge { char pad[0x10]; Primitive* prim0; Primitive* prim1; int index0; int index1; };
Edge* Primitive::next(Edge* e) {
    int index = (this == e->prim0) ? e->index0 : e->index1;
    ++index;
    return resolve(getEdge(index));
}
