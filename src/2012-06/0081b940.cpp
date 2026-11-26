// from server: 100% by Xemicl
// roc 2012-06 0081b940  unit: RBX::Mechanism  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081b940
//
// 0081b940  8b442404             mov eax, dword ptr [esp + 4]
// 0081b944  50                   push eax
// 0081b945  e8b67ffcff           call 0x7e3900
// 0081b94a  83c404               add esp, 4
// 0081b94d  85c0                 test eax, eax
// 0081b94f  7410                 je 0x81b961
// 0081b951  8d4808               lea ecx, [eax + 8]
// 0081b954  e887e21d00           call 0x9f9be0
// 0081b959  85c0                 test eax, eax
// 0081b95b  7404                 je 0x81b961
// 0081b95d  83c0f8               add eax, -8
// 0081b960  c3                   ret 
// 0081b961  33c0                 xor eax, eax
// 0081b963  c3                   ret 
// copied from an identical function in another client (function ?getGreatGrandParent@Node@RBX@@SAPAV12@PAV12@@Z)

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