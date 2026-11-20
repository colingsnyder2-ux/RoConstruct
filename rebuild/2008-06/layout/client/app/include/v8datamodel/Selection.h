#pragma once
#include "v8tree/Service.h"
#include "v8world/Controller.h"
#include "v8datamodel/SelectionChanged.h"
#include <algorithm>
#include <boost/get_pointer.hpp>

namespace RBX {
class __declspec(novtable) ISelectionBase {
    friend class Selection; // raiseAdded 00566ba0 / raiseRemoved 00566d50 call slot 0 (donor Selection.h)
    virtual void onSelectionChanged(const SelectionChanged&) = 0;
};
extern char sSelection[];

class Selection : public DescribedCreatable<Selection, Instance, sSelection>,
                  public Notifier<Selection, SelectionChanged>,
                  public Service,
                  public Listener<Instance, AncestorChanged> {
public:
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > selection;
    std::vector<ISelectionBase*> filteredSelections;
    Selection();                                                // 00568180
    virtual ~Selection();                                       // 00566f00
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
    void removeFilteredSelection(ISelectionBase*);              // 005670f0
    void addFilteredSelection(ISelectionBase*);                 // 00567180
    void toggleSelection(Instance*);                            // 00567210
    void raiseAdded(boost::shared_ptr<Instance>);               // 00566ba0
    void raiseRemoved(boost::shared_ptr<Instance>);             // 00566d50
    virtual void onEvent(const Instance*, AncestorChanged);     // 005682e0 (Listener<Instance, AncestorChanged>)
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > getSelection2() { return selection.read(); }
    template<class Iterator> void setSelection(Iterator first, Iterator last) {
        clearSelection();
        for (; first != last; first++) addToSelection(boost::get_pointer(*first));
    }
    void setSelection(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > value) {
        setSelection(value->begin(), value->end());
    }
};

template<>
const Name& NonFactoryProduct<Instance, static_cast<const char*>(0)>::className();
template<>
const Name& NonFactoryProduct<Instance, static_cast<const char*>(0)>::getClassName() const;

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
    virtual void onAncestorChanged(const AncestorChanged& event) {
        Instance::onAncestorChanged(event);
        if (!rootSelection) {
            rootSelection = shared_from<Selection>(ServiceProvider::create<Selection>(event.newParent));
            if (rootSelection) {
                for (std::vector<boost::shared_ptr<Instance> >::const_iterator it = rootSelection->selection->begin();
                     it != rootSelection->selection->end(); ++it) {
                    T* item = dynamic_cast<T*>(it->get());
                    if (item) filteredSelection.push_back(item);
                }
                rootSelection->addFilteredSelection(this);
            }
        }
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
