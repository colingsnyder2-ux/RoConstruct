#pragma once
#include "v8tree/Service.h"
#include "v8datamodel/SelectionChanged.h"

namespace RBX {
class ISelectionBase;
extern const char* sSelection;

// Original RTTI: notifier at 0x130, ancestor listener at 0x150;
// factory 00409620 allocates 0x174. Method behavior remains unrecovered.
class Selection : public DescribedCreatable<Selection, Instance, &sSelection>,
                  public Notifier<Selection, SelectionChanged>,
                  public Service,
                  public Listener<Instance, AncestorChanged> {
public:
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > selection;
    std::vector<ISelectionBase*> filteredSelections;
};
}
