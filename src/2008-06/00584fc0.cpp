// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_removemodifier841d42a3aa74d998.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
namespace RBX { class Instance { public: virtual ~Instance(); }; class IModelModifier : public Instance {}; }
struct ModelInstance { char reserved[0x1ec]; std::vector<RBX::IModelModifier*> modifiers;
 void removeIModelModifier(RBX::Instance* instance);
};
void ModelInstance::removeIModelModifier(RBX::Instance* instance) {
 RBX::IModelModifier* modifier=dynamic_cast<RBX::IModelModifier*>(instance);
 if(modifier) modifiers.erase(std::find(modifiers.begin(),modifiers.end(),modifier));
}
