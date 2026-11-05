// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll roc_espeon_filteredselectionconcretedtorfbda55476ce99fce.cpp

// Candidate translation unit (score above; library headers required).

#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <boost/shared_ptr.hpp>
#include <vector>
namespace RBX {
class SelectionChanged;
class ModelInstance;
class ISelectionBase {public:virtual void onSelectionChanged(const SelectionChanged&)=0;};
class Selection {public:void removeFilteredSelection(ISelectionBase*);};
class FilteredNative : public NonFactoryProduct<Instance,static_cast<const char*>(0)>,public Service,public ISelectionBase {
 boost::shared_ptr<Selection> rootSelection;
 std::vector<ModelInstance*> filteredSelection;
 public: virtual ~FilteredNative();virtual void onSelectionChanged(const SelectionChanged&);
};
FilteredNative::~FilteredNative(){if(rootSelection)rootSelection->removeFilteredSelection(this);}

}
