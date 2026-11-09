// from server: 100% by EspClaude
// roc 2007-08 006083b0  RBX::ClumpStage::removeAnchor (rbxgs v8world/ClumpStage.cpp), self-contained
#include <set>

namespace RBX {
class Clump;
class Primitive {
    char padding[0x20];
    Clump* clump;
public:
    Clump* getClump() const { return clump; }
};
class Anchor {
    Primitive* primitive;
public:
    Primitive* getPrimitive() const { return primitive; }
};

class ClumpStage {
    char padding[0x14];
    std::set<Anchor*> anchors;
    bool anchorsFind(Anchor* a) { return anchors.find(a) != anchors.end(); }
    void anchorsErase(Anchor* a);
    void destroyClump(Clump* c);
public:
    void removeAnchor(Anchor* a);
};

void ClumpStage::removeAnchor(Anchor* a)
{
    if (!anchorsFind(a))
    {
        Primitive* p = a->getPrimitive();
        if (p->getClump())
            destroyClump(p->getClump());
    }

    anchorsErase(a);
}
}
