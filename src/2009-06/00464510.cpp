// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x44];
    Instance* parent;
    Instance* getRootAncestor();
};
Instance* Instance::getRootAncestor()
{
    return parent ? parent->getRootAncestor() : this;
}
}
