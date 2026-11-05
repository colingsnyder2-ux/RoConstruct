// from server: 100% by EspClaude
// roc 2008-06 00552bb0  unit: RBX::RenderBase::AggregateChunk  size: 406 bytes
// roc-flags: /Od /GS /EHsc /MD
#include <algorithm>
#include <stdlib.h>

namespace RBX {
namespace RenderBase {

struct Primitive {
    char pad[0x24];
    int bounds;
};
struct Part {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual Primitive* getPrimitive();
};
struct PartVector {
    unsigned int size() const;
    Part*& operator[](unsigned int i);
};
struct Extents {
    float x, y, z;
    void expand(const int& b);
};
struct Entry {
    Extents extents;
    PartVector parts;
};
struct Iterator {
    void* cont;
    void* node;
    Iterator();
    Entry* operator->() const;
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
};
struct Map {
    Iterator begin();
    Iterator end();
};
struct Pred {
    void (*fn)(Entry&, bool);
    bool flag;
    Pred();
};
Pred makePred(void (*fn)(Entry&, bool), bool flag);
Pred for_each(Iterator first, Iterator last, Pred pred);

class AggregateChunk {
public:
    unsigned int total;
    unsigned int count;
    Map chunks;
    unsigned int numChunks();
    static bool showAll;
    static void sweep(Entry& e, bool all);
    Map& update(int maxIterations);
};

Map& AggregateChunk::update(int maxIterations)
{
    if (count > 1) {
        Iterator w = chunks.begin();
        Iterator n = chunks.end();
        for (; w != n; ++w) {
            if (w->parts.size() > 0) {
                unsigned int r = rand() % w->parts.size();
                w->extents.expand(w->parts[r]->getPrimitive()->bounds);
            }
        }
        unsigned int y = std::max((unsigned int)1, total / 20);
        int v = 0;
        while (true) {
            v++;
            if (numChunks() <= y)
                break;
            if (v == maxIterations)
                break;
            for_each(chunks.begin(), chunks.end(), makePred(&sweep, showAll));
        }
    }
    return chunks;
}

}
}
