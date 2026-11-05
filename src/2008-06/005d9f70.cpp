// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_filteredselectionnative1e2f104f3f7a2c9b.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
namespace RBX{class Instance{public:virtual ~Instance();};class PartInstance:public Instance{};}
struct SelectionChanged{boost::shared_ptr<RBX::Instance> added,removed;};
struct Selection{char prefix[12];std::vector<RBX::PartInstance*> filtered;void update(const SelectionChanged&);};
void Selection::update(const SelectionChanged&event){RBX::PartInstance*c=dynamic_cast<RBX::PartInstance*>(event.added.get());if(c)filtered.push_back(c);RBX::Instance*r=event.removed.get();if(r){std::vector<RBX::PartInstance*>::iterator it=std::find(filtered.begin(),filtered.end(),r);if(it!=filtered.end())filtered.erase(it);}}
