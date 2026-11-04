#define ContentProvider DonorContentProvider
#include "NativeSlingshotWorkerTrial.h"
#undef ContentProvider
#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderSlingshotOverlay.cpp"
#include "v8datamodel/PartInstance.h"
namespace RBX {
boost::shared_ptr<PartInstance> SlingshotTool::createProjectile() {
 std::vector<boost::shared_ptr<Instance> > result;
 ServiceProvider::create<ContentProvider>(workspace)->load(ContentId::fromAssets("Fonts\\SlingshotPellet.rbxm"), result);
 return boost::shared_static_cast<PartInstance>(result.front());
}
}
