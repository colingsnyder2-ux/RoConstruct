// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_backpacknativevisitor_10f23ffd264a3efb.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
namespace RBX {
class Instance;
typedef boost::shared_ptr<Instance> Shared;
typedef std::vector<Shared> Children;
class Instance {public:virtual void unused()=0;char padding[0x104];Children* children;};
struct Face {int getSurfaceType()const;void set(int);};
struct Surfaces {Face* face(int);};
class PartInstance:public Instance {public:Surfaces* surfaces();};
void __cdecl clearBackpack(Shared value){PartInstance* part=dynamic_cast<PartInstance*>(value.get());if(part){Surfaces* surfaces=part->surfaces();for(int i=0;i<6;++i){if(surfaces->face(i)->getSurfaceType()==2) surfaces->face(i)->set(3);}}if(value->children) std::for_each(value->children->begin(),value->children->end(),boost::bind(clearBackpack,_1));}
}
