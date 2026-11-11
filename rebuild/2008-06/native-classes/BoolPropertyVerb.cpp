// >>> native-status (generated) -- do not edit >>>
// BoolPropertyVerb | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 236591e5 | roc native-status --write
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/v8datamodel/Workspace.h"
#include "../native-headers/util/RunStateOwner.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/v8datamodel/Selection.h"
#include "../native-headers/v8datamodel/PVInstance.h"
#include "../native-headers/v8datamodel/ModelInstance.h"
#include "../native-headers/Network/Players.h"
#include "../native-headers/util/Sound.h"
#include <stdexcept>
#include <boost/bind.hpp>

namespace RBX {

inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);

namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
class Server { public: static bool serverIsPresent(const Instance*, bool); };
}

static __declspec(noinline) void checkRunPermissions(Instance* instance) {
    if (Network::Client::clientIsPresent(instance, true) && !Network::Server::serverIsPresent(instance, true)) {
        std::string message("Insufficinet permissions");
        throw std::runtime_error(message);
    }
}

bool __cdecl testBooleanProperty(const Name* name, boost::shared_ptr<Instance> item) {
    Reflection::PropertyIterator iter = item->findProperty(*name);
    if (iter != item->properties_end() && dynamic_cast<const Reflection::TypedPropertyDescriptor<bool>*>(&iter.getDescriptor()))
        if ((*iter).getValue<bool>()) return true;
    return false;
}

struct SetBooleanProperty {
    const Name* name;
    bool value;
    SetBooleanProperty(const Name* n, bool v) : name(n), value(v) {}
    void operator()(boost::shared_ptr<Instance>) const;
};

void SetBooleanProperty::operator()(boost::shared_ptr<Instance> item) const {
    Reflection::PropertyIterator iter = item->findProperty(*name);
    if (iter != item->properties_end() && dynamic_cast<const Reflection::TypedPropertyDescriptor<bool>*>(&iter.getDescriptor()))
        if ((*iter).getValue<bool>() != value) (*iter).setValue<bool>(value);
}

void BoolPropertyVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    bool value = !isChecked();
    std::for_each(selection->selection->begin(), selection->selection->end(), SetBooleanProperty(&propertyName, value));
    recordCameraHistory(propertyName.c_str(), dataModel);
    state->setDirty(true);
}

bool BoolPropertyVerb::isChecked() const {
    return std::find_if(selection->selection->begin(), selection->selection->end(), boost::bind(testBooleanProperty, &propertyName, _1)) != selection->selection->end();
}

}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_bi::value<RBX::Name const *>;
