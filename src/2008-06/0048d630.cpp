// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_appearanceforeachnativea918b1866f24f7f6.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/ModelInstance.h"
#include <boost/bind.hpp>
#include <vector>
#include <algorithm>
namespace RBX {
void setAppearanceParent(boost::shared_ptr<Instance> parent, boost::shared_ptr<Instance> child);
void applyAppearance(boost::shared_ptr<ModelInstance> character, boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > appearance) {
 std::for_each(appearance->begin(),appearance->end(),boost::bind(&setAppearanceParent,character,_1));
}
}
