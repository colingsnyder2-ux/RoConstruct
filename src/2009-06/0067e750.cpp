// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Edge;
class Contact;
class JointStage {
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void onEdgeAdded(Edge* e);
	virtual void onEdgeRemoving(Edge* e);
};
class Edge { public: virtual ~Edge(); };
class Contact : public Edge {};
class World {
public:
	char pad0[0x78];
	int numContacts;
	char pad1[0xb8 - 0x7c];
	JointStage* jointStage;
	void insertContact(Contact* c);
};
void World::insertContact(Contact* c)
{
	jointStage->onEdgeAdded(c);
	numContacts++;
}
}
