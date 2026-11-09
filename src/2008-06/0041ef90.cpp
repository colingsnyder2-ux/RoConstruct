// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_selectionrttid752eebd46283952.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
namespace RBX {class Instance {public:virtual void unused();}; class SpecialShape:public Instance{};class PartInstance:public Instance{};}
using namespace RBX;
struct Provider {char pad[0x154];std::vector<boost::shared_ptr<Instance> >* range;boost::shared_ptr<Instance> first();};
struct Owner {Provider* resolve();};
struct S {char pad[0x20];Owner* owner;Instance*f();};
Instance* S::f(){Provider*p=owner?owner->resolve():0;if(p->range->size()==1){Instance*object=p->first().get();if(dynamic_cast<PartInstance*>(object))return object;if(dynamic_cast<SpecialShape*>(object))return object;}return 0;}
