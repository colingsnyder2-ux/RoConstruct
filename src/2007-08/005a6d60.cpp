// from server: 100% by EspClaude
// roc 2007-08 005a6d60  unit: RBX::Humanoid  size: 233 bytes
// Humanoid::getIgnorePrims (2007 form): push each body part's primitive (PartInstance+0x1d8).
// roc-flags: /O2 /GS /EHsc /MD
#include <vector>
class Primitive;
extern template class std::vector<const Primitive*>;
class PartInstance {
public:
    char pad[0x1d8];
    Primitive* primitive;
    Primitive* getPrimitive() const { return primitive; }
};
class Humanoid {
public:
    PartInstance* getTorso();
    PartInstance* getHead();
    PartInstance* getLeftArm();
    PartInstance* getRightArm();
    PartInstance* getLeftLeg();
    PartInstance* getRightLeg();
    void getIgnorePrims(std::vector<const Primitive*>& ignore);
};

static inline void addPrim(PartInstance* part, std::vector<const Primitive*>& ignore)
{
    if (part) {
        const Primitive* prim = part->getPrimitive();
        if (prim)
            ignore.push_back(prim);
    }
}

void Humanoid::getIgnorePrims(std::vector<const Primitive*>& ignore)
{
    addPrim(getTorso(), ignore);
    addPrim(getHead(), ignore);
    addPrim(getLeftArm(), ignore);
    addPrim(getRightArm(), ignore);
    addPrim(getLeftLeg(), ignore);
    addPrim(getRightLeg(), ignore);
}
