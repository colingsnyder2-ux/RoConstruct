// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_renderableselect2ea9de329b17fa65.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <util/IRenderable.h>
namespace RBX{
class Instance;
struct SP{Instance*p;void*c;};
struct Children{std::vector<SP> v;};
class Instance{public:virtual ~Instance();char pad[0xcc];Children*children;char pad2[0x34];size_t numChildren()const{return children?children->v.size():0;}Instance*getChild(size_t i)const{return children->v[i].p;}};
class Accoutrement:public Instance,public IRenderable{public:virtual void render3dSelect(Adorn*,SelectState);};
void Accoutrement::render3dSelect(Adorn*adorn,SelectState state){for(size_t i=0;i<numChildren();++i){IRenderable*r=dynamic_cast<IRenderable*>(getChild(i));if(r)r->render3dSelect(adorn,state);}}
}
