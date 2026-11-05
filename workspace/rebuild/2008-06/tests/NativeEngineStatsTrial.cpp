#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
namespace RBX {
class SpatialHash { public: __declspec(noinline) void doStats(); };
class ContactManager { SpatialHash* spatialHash; public: void doStats(); };
__declspec(noinline) void ContactManager::doStats() { spatialHash->doStats(); }
// Diagnostic offsets independently checked against construction and destruction.
class World { char prefix[0x84]; ContactManager* contactManager; public: ContactManager* getContactManager() { return contactManager; } };
class Workspace { char prefix[0x2e4]; World* world; public: World* getWorld() { return world; } };
void EngineStatsCommand::doIt(IDataState*) {
    dataModel->getWorkspace()->getWorld()->getContactManager()->doStats();
}
}
