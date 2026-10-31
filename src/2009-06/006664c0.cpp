// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Edge { public: virtual ~Edge(); char pad[0x1c]; };
class SpanningEdge { public: virtual void span(); char pad[0x74]; };
class Joint : public Edge, public SpanningEdge { public: virtual ~Joint(); };
class KernelIndex { public: int idx; };
class Connector : public KernelIndex { public: virtual void conn(); };
class KernelJoint : public Joint, public Connector {
public:
    virtual ~KernelJoint();
    virtual void kj();
};
KernelJoint::~KernelJoint() {}
}
