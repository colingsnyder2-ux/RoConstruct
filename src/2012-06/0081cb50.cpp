// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Node {
    virtual void v0();
    virtual int kind();
    int pad;
    Node* next;
    int f();
};
struct S {
    char pad[0xac];
    Node* head;
    int run();
};
int S::run() {
    Node* o = head;
    while (o->kind() != 5) o = o->next;
    return o->f();
}
