#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "RocketContentTypes.cpp"
#include "NativeRocketWorkerTrial.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
namespace RBX {
boost::shared_ptr<PartInstance> RocketTool::createProjectile() {
 std::vector<boost::shared_ptr<Instance> > instances;
 ServiceProvider::create<ContentProvider>(workspace)->load(ContentId::fromAssets("Fonts\\Rocket.rbxm"),instances);
 return boost::shared_static_cast<PartInstance>(instances.front());
}
}
