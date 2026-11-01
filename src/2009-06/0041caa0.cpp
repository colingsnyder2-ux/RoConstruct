// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct Node {
	char pad[0x48];
	Node* m_pParent;
	bool IsChildOf(Node* p) const;
};
bool Node::IsChildOf(Node* p) const
{
	for (Node* n = m_pParent; p != n; n = n->m_pParent)
		if (n == 0) return false;
	return true;
}
