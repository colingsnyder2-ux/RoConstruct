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
#include "v8xml/SerializerV2.h"
void __cdecl collectSelection(XmlElement*, boost::shared_ptr<RBX::Instance>);
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
void DuplicateSelectionVerb::doIt(IDataState* state) {
 checkRunPermissions(dataModel);
 std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
 ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
 std::for_each(selection->selection->begin(),selection->selection->end(),boost::bind(collectSelection,root.get(),_1));
 SerializerV2::isolateHandles(root.get());
 std::vector<boost::shared_ptr<Instance> > instances;
 workspace->insertItems(root.get(),instances,INSERT_TO_3D_VIEW,ALLOW_PROMPTS);
 selection->setSelection(instances.begin(),instances.end());
 ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel))->playSound(PING_SOUND);
 recordCameraHistory(getName().c_str(),dataModel); state->setDirty(true);
}
}
