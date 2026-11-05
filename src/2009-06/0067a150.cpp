// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Node;
void setX(Node* n, bool v);
template<class F> struct Bind { F f; bool v; };
class Container { public: template<class F> void visit(F f); };
class Instance {
public:
	void onDescendentAdded(Instance* d, int x);
};
class Lighting : public Instance {
public:
	char pad[0x234];
	Container* target;
	Instance* part;
	void onDescendentAdded(Instance* d, int x);
};
void Lighting::onDescendentAdded(Instance* d, int x) {
	Instance::onDescendentAdded(d, x);
	if (part == d) {
		Bind<void (*)(Node*, bool)> b = { &setX, true };
		if (target)
			target->visit(b);
	}
}
}
