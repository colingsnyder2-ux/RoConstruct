// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Hopper.h"
#include <stdexcept>

namespace RBX {

namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
class Server { public: static bool serverIsPresent(const Instance*, bool); };
}

static __declspec(noinline) void checkRunPermissions(Instance* instance)
{
    if (Network::Client::clientIsPresent(instance, true) && !Network::Server::serverIsPresent(instance, true)) {
        std::string message("Insufficinet permissions");
        throw std::runtime_error(message);
    }
}

bool ClearStarterpack::isEnabled() const
{
    if (dataModel) {
        StarterPackService* starter = ServiceProvider::create<StarterPackService>(static_cast<const ServiceProvider*>(dataModel));
        if (starter) return starter->numChildren() > 0;
    }
    return false;
}

void ClearStarterpack::doIt(IDataState*)
{
    checkRunPermissions(dataModel);
    StarterPackService* starter = ServiceProvider::create<StarterPackService>(static_cast<const ServiceProvider*>(dataModel));
    if (starter) starter->removeAllChildren();
}

}

namespace RBX {
ClearStarterpack::ClearStarterpack(RBX::DataModel* dm)
    : Verb(dm, std::string("ClearStarterpack")),
      dataModel(dm)
{
}
}

