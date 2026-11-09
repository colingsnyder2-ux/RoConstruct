// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Node { public: virtual void v0(); virtual int getType(); char pad[4]; Node* parent; };
class PhysicsService { char pad[0x88]; Node* root; public: Node* find(); };
Node* PhysicsService::find() { Node* n = root; while (n->getType() != 6) n = n->parent; return n; } }
