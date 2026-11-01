// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace RBX {
class Instance { public: virtual ~Instance(); virtual void onChildAdded(Instance* child); char d[0x8c - 4]; };
class IModelModifier { public: virtual ~IModelModifier(); };
class ModelInstance : public Instance {
    char pad[0x100 - 0x8c];
    std::vector<IModelModifier*> modifiers;
public:
    virtual void onChildAdded(Instance* child);
};
void ModelInstance::onChildAdded(Instance* child)
{
    if (IModelModifier* m = dynamic_cast<IModelModifier*>(child))
        modifiers.push_back(m);
}
}
