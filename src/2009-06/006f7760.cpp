// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Primitive;
class Contact {
public:
    char pad[0x10];
    Primitive* prim0;
    Primitive* prim1;
    Primitive* otherPrimitive(const Primitive* p) const { return (p == prim0) ? prim1 : prim0; }
    bool computeIsAdjacent(float spaceAllowed);
};
class Primitive {
public:
    Contact* getFirstContact();
    Contact* getNextContact(Contact* prev);
};
class RunDragger {
private:
    bool adjacent(Primitive* p0, Primitive* p1);
};
bool RunDragger::adjacent(Primitive* p0, Primitive* p1)
{
    for (Contact* current = p0->getFirstContact(); current != 0; current = p0->getNextContact(current))
    {
        if (current->otherPrimitive(p0) == p1)
            return current->computeIsAdjacent(0.01f);
    }
    return false;
}
}
