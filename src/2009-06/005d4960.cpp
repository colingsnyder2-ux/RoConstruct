// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    const Instance* getParent() const { return parent; }
    const Instance* getRootAncestor() const;
    const Instance* rootAncestor() const { return getParent() ? getParent()->getRootAncestor() : this; }
};
class Selection : public Instance {
public:
    void removeFromSelection(const Instance* instance);
    void onAncestorChanged(const Instance* source);
};
void Selection::onAncestorChanged(const Instance* source)
{
    const Instance* sourceRoot = source->getParent() != 0 ? source->getParent()->getRootAncestor() : source;
    if (sourceRoot != rootAncestor())
        removeFromSelection(source);
}
}
