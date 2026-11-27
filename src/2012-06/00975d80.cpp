// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Node { Node* next; Node* prev; };
struct It { Node* n; };
struct S {
    int size;
    It erase(Node* n);
};
It S::erase(Node* n) {
    Node* nx = n->next;
    if (nx) { Node* pv = n->prev; pv->next = nx; nx->prev = pv; }
    --size;
    n->next = 0; n->prev = 0;
    It r; r.n = nx; return r;
}