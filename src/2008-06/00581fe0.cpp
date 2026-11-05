// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_filteredmodel1d2024f80763ca6e.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/ModelInstance.h"
#include <vector>
#include <boost/shared_ptr.hpp>
typedef std::vector<boost::shared_ptr<RBX::Instance> > Children;
struct Listener {virtual ~Listener();};
struct Prefix {virtual ~Prefix();char padding[0x12c];};
struct State {char prefix[0x154];Children* selected;void addFilteredSelection(Listener*);};
extern State* createSelection(RBX::Instance*);
extern boost::shared_ptr<State> sharedSelection(State*);
struct Filter:Prefix,Listener {boost::shared_ptr<State> root;std::vector<RBX::ModelInstance*> selected;void initialize(const RBX::AncestorChanged&);void update(const RBX::AncestorChanged&);};
void Filter::update(const RBX::AncestorChanged& event){initialize(event);if(!root){root=sharedSelection(createSelection(event.newParent));if(root){for(Children::const_iterator i=root->selected->begin();i!=root->selected->end();i++){RBX::ModelInstance* c=dynamic_cast<RBX::ModelInstance*>(i->get());if(c)selected.push_back(c);}root->addFilteredSelection(this);}}}
