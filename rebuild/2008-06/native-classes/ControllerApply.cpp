// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ControllerApply | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 57b138ea | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"

namespace RBX {
struct DifferentController {
    Controller::ControllerType value;
    explicit DifferentController(Controller::ControllerType value) : value(value) {}
    bool operator()(PVInstance* item) const { return item->getControllerType() != value; }
};

static __declspec(noinline) void setController(Controller::ControllerType value, PVInstance* item)
{
    item->setControllerType(value);
}

struct ApplyController {
    void (*fn)(Controller::ControllerType, PVInstance*);
    Controller::ControllerType value;
    explicit ApplyController(Controller::ControllerType value) : fn(setController), value(value) {}
    void operator()(PVInstance* item) const { fn(value, item); }
};

template<class T> T* FilteredSelection<T>::findDifferent(Controller::ControllerType value)
{
    typename std::vector<T*>::iterator found = std::find_if(
        filteredSelection.begin(), filteredSelection.end(), DifferentController(value));
    return found != filteredSelection.end() ? *found : NULL;
}

template PVInstance* FilteredSelection<PVInstance>::findDifferent(Controller::ControllerType);

void ControllerCommand::applyController(int type)
{
    FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(
        static_cast<const ServiceProvider*>(dataModel));
    Controller::ControllerType desired = static_cast<Controller::ControllerType>(type);
    Controller::ControllerType value = selected->findDifferent(desired) ? desired : Controller::NO_CONTROLLER;
    std::for_each(selected->items().begin(), selected->items().end(), ApplyController(value));
}
}
