// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Obj {
    virtual ~Obj();
    virtual bool less(Obj* other);
};
struct Node {
    int a;
    Node* parent;
    char pad[0x1c];
    Obj* obj;
};
Node* __cdecl stepUp(int side, Node* node, Obj** best, int* bestSide)
{
    Obj* o = node->obj;
    if (o) {
        if (*best == 0 || (*best)->less(o)) {
            *best = o;
            *bestSide = side;
        }
    }
    return node->parent;
}
