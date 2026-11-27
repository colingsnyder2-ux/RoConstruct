// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Node { virtual void v0(); virtual int type(); int pad; Node* next; };
struct S { char pad[172]; Node* node; Node* f(); };
Node* S::f()
{
    Node* p = node;
    while (p->type() != 7)
        p = p->next;
    return p;
}
