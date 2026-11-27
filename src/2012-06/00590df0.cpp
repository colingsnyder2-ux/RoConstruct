// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { int v; };
struct Node { int a; int v; };
struct S {
    int pad[2];
    char* link;
    R f() const;
};
R S::f() const {
    Node* n = link ? (Node*)(link - 9) : 0;
    R r; r.v = n->v; return r;
}