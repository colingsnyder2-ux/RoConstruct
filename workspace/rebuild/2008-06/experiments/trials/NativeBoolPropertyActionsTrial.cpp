#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Players.h"
#include "util/Sound.h"
#include <stdexcept>
#include "tool/MegaDragger.h"
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
bool __cdecl testBooleanProperty(const Name*,boost::shared_ptr<Instance>);
struct SetBooleanProperty { const Name* name; bool value; SetBooleanProperty(const Name* n, bool v):name(n),value(v){} void operator()(boost::shared_ptr<Instance>) const; };
void BoolPropertyVerb::doIt(IDataState* state) {
 checkRunPermissions(dataModel);
 bool value = !isChecked();
 std::for_each(selection->selection->begin(),selection->selection->end(),SetBooleanProperty(&propertyName,value));
 recordCameraHistory(propertyName.c_str(),dataModel);
 state->setDirty(true);
}
bool BoolPropertyVerb::isChecked() const {
 return std::find_if(selection->selection->begin(),selection->selection->end(),boost::bind(testBooleanProperty,&propertyName,_1)) != selection->selection->end();
}
}
