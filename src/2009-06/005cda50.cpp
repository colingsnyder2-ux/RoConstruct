// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    bool isAncestorOf(const Instance* descendent) const;
};
bool Instance::isAncestorOf(const Instance* descendent) const
{
    while (descendent) {
        if (descendent == this)
            return true;
        descendent = descendent->parent;
    }
    return false;
}
}
