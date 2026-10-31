// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class CoordinateFrame { public: float m[12]; }; }
namespace RBX {
class Body {
public:
    char pad0[4];
    Body* parent;
    char pad1[0x98 - 8];
    int stateIndex;
    void updateStateIndex();
    Body* getParent() const { return parent; }
    int getStateIndex() { updateStateIndex(); return stateIndex; }
};
class Link {
public:
    virtual void computeChildInParent(G3D::CoordinateFrame& answer) const;
    Body* body;
    char pad[0x98 - 8];
    mutable G3D::CoordinateFrame childInParent;
    mutable int stateIndex;
    const G3D::CoordinateFrame& getChildInParent() const;
};
const G3D::CoordinateFrame& Link::getChildInParent() const
{
    int bodyStateIndex = body->getParent()->getStateIndex();
    if (stateIndex != bodyStateIndex)
    {
        computeChildInParent(childInParent);
        stateIndex = bodyStateIndex;
    }
    return childInParent;
}
}
