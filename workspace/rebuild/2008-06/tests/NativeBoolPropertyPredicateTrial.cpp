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
bool __cdecl testBooleanProperty(const Name* name,boost::shared_ptr<Instance> item) {
 Reflection::PropertyIterator iter = item->findProperty(*name);
 if (iter != item->properties_end() && dynamic_cast<const Reflection::TypedPropertyDescriptor<bool>*>(&iter.getDescriptor()))
  if ((*iter).getValue<bool>()) return true;
 return false;
}
}
