// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad_4[0x44];
    Instance* parent;
    Instance* getParent() const { return parent; }
};
class PVInstance : public Instance {
public:
    PVInstance* getTopLevelPVParent();
};
PVInstance* PVInstance::getTopLevelPVParent()
{
    PVInstance* answer = this;
    Instance* par = getParent();
    while (PVInstance* p = dynamic_cast<PVInstance*>(par)) {
        par = p->getParent();
        answer = p;
    }
    return answer;
}
}
