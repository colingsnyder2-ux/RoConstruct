#pragma once
// >>> native-status (generated) -- do not edit >>>
// Selection | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src e733b74c | roc native-status --write
#include "v8tree/Service.h"
#include "v8world/Controller.h"
#include "v8datamodel/SelectionChanged.h"
#include <algorithm>
#include <boost/get_pointer.hpp>

namespace RBX {
class __declspec(novtable) ISelectionBase {
    virtual void onSelectionChanged(const SelectionChanged&) = 0;
};
extern char sSelection[];

// Original RTTI: notifier at 0x130, ancestor listener at 0x150;
// factory 00409620 allocates 0x174. Method behavior remains unrecovered.
class Selection : public DescribedCreatable<Selection, Instance, sSelection>,
                  public Notifier<Selection, SelectionChanged>,
                  public Service,
                  public Listener<Instance, AncestorChanged> {
public:
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > selection;
    std::vector<ISelectionBase*> filteredSelections;
    size_t size() const { return selection->size(); }
    boost::shared_ptr<Instance> front() const;
    boost::shared_ptr<Instance> back() const;
    void clearSelection();
    void addToSelection(Instance*);
    bool isSelected(const Instance*) const;                     // 00424eb0
    void removeFromSelection(const Instance*);                  // 00567c10
    void setSelection(Instance*);                               // 00567770
    std::vector<boost::shared_ptr<Instance> >::const_iterator begin() const; // 00413d10
    std::vector<boost::shared_ptr<Instance> >::const_iterator end() const;   // 00413d40
    void removeFilteredSelection(ISelectionBase*);
    // get_pointer: raw-pointer iterators (CInstanceExplorer 00420d20) and shared_ptr ones alike
    template<class Iterator> void setSelection(Iterator first, Iterator last) {
        clearSelection();
        for (; first != last; first++) addToSelection(boost::get_pointer(*first));
    }
};

template<class T>
class FilteredSelection : public NonFactoryProduct<Instance, static_cast<const char*>(0)>,
                          public Service, public ISelectionBase {
    friend class CanNotSelectCommand;
    friend class UngroupSelectionVerb;
    boost::shared_ptr<Selection> rootSelection;
    std::vector<T*> filteredSelection;
public:
    FilteredSelection() { Instance::setName("FilteredSelection"); }
    virtual ~FilteredSelection() {
        if (rootSelection) rootSelection->removeFilteredSelection(this);
    }
    T* findFirst(bool (*predicate)(T*));
    T* findDifferent(Controller::ControllerType);
    size_t size() const { return filteredSelection.size(); }
    const std::vector<T*>& items() const { return filteredSelection; }
    T* front() { return filteredSelection.empty() ? NULL : filteredSelection.front(); }
    virtual void onSelectionChanged(const SelectionChanged& event) {
        T* added = dynamic_cast<T*>(event.addedItem.get());
        if (added) filteredSelection.push_back(added);
        Instance* removed = event.removedItem.get();
        if (removed) {
            typename std::vector<T*>::iterator it = std::find(filteredSelection.begin(), filteredSelection.end(), removed);
            if (it != filteredSelection.end()) filteredSelection.erase(it);
        }
    }
};
}
