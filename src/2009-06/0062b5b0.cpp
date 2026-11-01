// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    Instance* getParent() const { return parent; }
};
Instance* topAncestorBelowRoot(Instance* p) {
    Instance* a = p->getParent();
    Instance* b = a->getParent();
    while (b->getParent()) {
        a = b;
        b = b->getParent();
    }
    return a;
}
}
