// from server: 89% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Node { unsigned short a; int b; int v0, v1, v2; int z0, z1, z2; };
Node* allocNode();
struct BallBallContact {
    Node* head;
    void add(const unsigned short* a, const int* b, const int* v);
};
void BallBallContact::add(const unsigned short* a, const int* b, const int* v) {
    Node* n = head;
    if (n) head = *(Node**)n; else n = allocNode();
    if (!n) return;
    n->b = *b;
    n->a = *a;
    n->v0 = v[0]; n->v1 = v[1]; n->v2 = v[2];
    n->z0 = 0; n->z1 = 0; n->z2 = 0;
}