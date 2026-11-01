// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct N { char pad[0x48]; N* parent; char pad2[0x150-0x4c]; int value; };
int topValue(N* p) {
    N* x = p->parent;
    N* y = x->parent;
    while (y->parent) { x = y; y = y->parent; }
    return x->value;
}
