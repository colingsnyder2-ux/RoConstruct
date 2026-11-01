// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_b8dd3c6ee7f40e32.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _DLL
#define _DLL
#endif
#include <boost/shared_ptr.hpp>
#include <vector>
namespace RBX {
class Instance;
class SelectionChanged {
public:
    const boost::shared_ptr<Instance> addedItem;
    const boost::shared_ptr<Instance> removedItem;
    SelectionChanged(boost::shared_ptr<Instance> addedItem, boost::shared_ptr<Instance> removedItem);
    ~SelectionChanged();
};
class __declspec(novtable) ISelectionBase {
public:
    virtual void VTable0x00(const SelectionChanged& event) = 0;
};
class SelectionSignal {
public:
    void operator()(const SelectionChanged&);
};
class Selection {
public:
    char pad0[0x94];
    std::vector<ISelectionBase*> filteredSelections;
    char pad1[0xcc - 0x94 - sizeof(std::vector<ISelectionBase*>)];
    SelectionSignal selectionChanged;
    void raiseRemoved(boost::shared_ptr<Instance> item);
};
void Selection::raiseRemoved(boost::shared_ptr<Instance> item)
{
    SelectionChanged event(boost::shared_ptr<Instance>(), item);
    for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); ++iter) {
        (*iter)->VTable0x00(event);
    }
    selectionChanged(event);
}
}
