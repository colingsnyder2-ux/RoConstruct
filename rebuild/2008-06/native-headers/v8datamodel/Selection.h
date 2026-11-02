#pragma once
#include "v8tree/Service.h"
#include "v8world/Controller.h"
#include "v8datamodel/SelectionChanged.h"
#include <algorithm>

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
    void clearSelection();
    void addToSelection(Instance*);
    void removeFilteredSelection(ISelectionBase*);
    template<class Iterator> void setSelection(Iterator first, Iterator last) {
        clearSelection();
        for (; first != last; first++) addToSelection(first->get());
    }
};

template<class T>
class FilteredSelection : public NonFactoryProduct<Instance, static_cast<const char*>(0)>,
                          public Service, public ISelectionBase {
    friend class CanNotSelectCommand;
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
