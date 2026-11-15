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
// The original RTTI (.?AV?$FactoryProduct@VSelection@RBX@@VInstance@2@$1?sSelection@2@3QBDB@RBX@@, string 0082ec58)
// says const char array, but the identity registry binds every Selection template row to the 3PADA (char array)
// names, so the declaration stays non-const until those rows are rebound (proposal; const loses 19 proven rows).
extern char sSelection[];

// Original RTTI: notifier at 0x130, ancestor listener at 0x150;
// factory 00409620 allocates 0x174 and calls the constructor 00568180.
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
    // 00566a80: out-of-line copy emitted for the "Get" BoundFuncDesc (007f3330); calls CopyOnWrite::read 004915b0
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > getSelection2() { return selection.read(); }
    // get_pointer: raw-pointer iterators (CInstanceExplorer 00420d20) and shared_ptr ones alike
    template<class Iterator> void setSelection(Iterator first, Iterator last) {
        clearSelection();
        for (; first != last; first++) addToSelection(boost::get_pointer(*first));
    }
    // 00568330: out-of-line copy emitted for the "Set" BoundFuncDesc (007f3360); calls setSelection<const_iterator> 00413b00
    void setSelection(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > value) {
        setSelection(value->begin(), value->end());
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
