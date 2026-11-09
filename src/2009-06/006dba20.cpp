// from server: 95% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class IndexBase { public: virtual ~IndexBase(); void setIndex(int i); };
class Primitive;
class NodeA { public: virtual void destroy(bool b); };
class NodeB { public: virtual ~NodeB(); int pad; IndexBase index; };
class NodeC : public IndexBase { public: virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void release(bool b); };
class Geo {
public:
	virtual ~Geo();
	int pad;
	IndexBase index;
	NodeA* getA();
	NodeB* getB();
	NodeC* getC();
};
template<class T> class Set { public: void erase(const T* const& key); };
class TreeStage {
public:
	char pad[0x28];
	Set<NodeA> nodes;
	void removeNode(NodeA* a);
	void onRemoving(Geo* geo);
};
void TreeStage::onRemoving(Geo* geo)
{
	NodeA* a = geo->getA();
	NodeB* b = geo->getB();
	NodeC* c = geo->getC();
	removeNode(a);
	nodes.erase(a);
	b->index.setIndex(0);
	c->setIndex(0);
	geo->index.setIndex(0);
	delete b;
	if (c)
		c->release(true);
	if (a)
		a->destroy(true);
}
}
