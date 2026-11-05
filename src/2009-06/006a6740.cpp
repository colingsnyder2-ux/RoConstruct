// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class CoordinateFrame { public: float m[12]; CoordinateFrame(); }; }
namespace RBX {
class Primitive;
class StepJointsStage; class MovingAssemblyStage;
class IPipelined { public: virtual ~IPipelined(); };
class Edge : public IPipelined {
public:
    Edge(Primitive* p0, Primitive* p1);
    virtual ~Edge();
    char edgePad[0x1c];
};
class SpanningEdge {
public:
    virtual ~SpanningEdge() {}
};
template<class Tag> class ListHook {
public:
    void* next; void* prev;
    ListHook() : next(0), prev(0) {}
};
class Joint : public Edge, public SpanningEdge, public ListHook<StepJointsStage>, public ListHook<MovingAssemblyStage> {
public:
    Joint();
    virtual ~Joint();
    void* jointOwner;
    G3D::CoordinateFrame jointCoord0;
    G3D::CoordinateFrame jointCoord1;
};
Joint::Joint() : Edge(0, 0), jointOwner(0)
{
}
}
