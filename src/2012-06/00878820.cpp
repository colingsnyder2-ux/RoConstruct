// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct Ref { virtual void a(); virtual void b(); virtual void dispose(); int pad; volatile long cnt; };
struct Node { Node* left; Node* parent; Node* right; int k; Ref* ref; int pad; char color; char isnil; };
struct T { void erase(Node* n); };
void T::erase(Node* root) {
  for (Node* p = root; !p->isnil; root = p) {
    erase(p->right);
    p = p->left;
    Ref* r = root->ref;
    if (r && _InterlockedDecrement(&r->cnt) == 0) r->dispose();
    operator delete(root);
  }
}
