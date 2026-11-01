// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2009 Edge::getEdgeType is vtable slot 4 (was 3 in 2008)
namespace RBX {
namespace Sim { enum EdgeState { UNDEFINED, STEPPING, SLEEPING, TOUCHING, TOUCHING_SLEEPING }; }
class Edge {
public:
    enum EdgeType { JOINT, CONTACT };
    virtual ~Edge();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual EdgeType getEdgeType() const;
    Sim::EdgeState getEdgeState() const { return edgeState; }
    int pad;
    Sim::EdgeState edgeState;
};
class Contact : public Edge {};
class Joint : public Edge {};
class SleepStage {
public:
    void wakeEdge(Edge* e);
    void changeContactState(Contact* c, Sim::EdgeState s);
    void changeJointState(Joint* j, Sim::EdgeState s);
};
void SleepStage::wakeEdge(Edge* e)
{
	Sim::EdgeState state = e->getEdgeState();

	if (e->getEdgeType() == Edge::CONTACT) {
		if (state == Sim::TOUCHING_SLEEPING) {
			changeContactState(static_cast<Contact*>(e), Sim::TOUCHING);
		}
		else if (state == Sim::SLEEPING) {
			changeContactState(static_cast<Contact*>(e), Sim::STEPPING);
		}
	}
	else if (state == Sim::SLEEPING) {
		changeJointState(static_cast<Joint*>(e), Sim::STEPPING);
	}
}
}
