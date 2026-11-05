// from server: 100% by colin
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_manual_pvselect_dd653aa92db1176e.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
namespace RBX{class Instance{public:virtual ~Instance();};class PVInstance:public Instance{};}
struct SelectionChanged{boost::shared_ptr<RBX::Instance> added,removed;};
struct Selection{char prefix[12];std::vector<RBX::PVInstance*> filtered;void update(const SelectionChanged&);};
void Selection::update(const SelectionChanged&event){RBX::PVInstance*c=dynamic_cast<RBX::PVInstance*>(event.added.get());if(c)filtered.push_back(c);RBX::Instance*r=event.removed.get();if(r){std::vector<RBX::PVInstance*>::iterator it=std::find(filtered.begin(),filtered.end(),r);if(it!=filtered.end())filtered.erase(it);}}
