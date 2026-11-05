// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x44];
    Instance* parent;
    bool isAncestorOf(const Instance* descendant) const;
};
bool Instance::isAncestorOf(const Instance* descendant) const
{
    if (descendant == 0)
        return false;
    const Instance* p = descendant;
    do {
        p = p->parent;
        if (p == this)
            return true;
    } while (p);
    return false;
}
}
