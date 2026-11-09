// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class TreeNode {
public:
	char pad[0x20];
	TreeNode* parent;
	TreeNode* getParent() const;
};
class Base8 { public: int a, b; };
class Node : public Base8, public TreeNode {
public:
	static Node* getGrandParent(Node* n);
	static Node* getGreatGrandParent(Node* n);
};
Node* Node::getGreatGrandParent(Node* n)
{
	if (Node* g = getGrandParent(n))
		return static_cast<Node*>(g->getParent());
	return 0;
}
}
