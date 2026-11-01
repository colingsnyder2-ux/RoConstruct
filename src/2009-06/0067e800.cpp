// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Node {
    virtual void f0();
    virtual int getType();
    int pad4;
    Node* parent;
};
struct Owner {
    char pad[0xb8];
    Node* node;
    Node* findAncestor();
};
Node* Owner::findAncestor()
{
    Node* p = node;
    while (p->getType() != 7)
        p = p->parent;
    return p;
}
