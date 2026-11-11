// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
// >>> native-status (generated) -- do not edit >>>
// RocketToolProjectile | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c3e8ef25 | roc native-status --write
#include "util/NativeContentProvider.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
namespace RBX {
boost::shared_ptr<PartInstance> RocketTool::createProjectile() {
 std::vector<boost::shared_ptr<Instance> > result;
 ServiceProvider::create<ContentProvider>(workspace)->load(ContentId::fromAssets("Fonts\\Rocket.rbxm"), result);
 return boost::shared_static_cast<PartInstance>(result.front());
}
}
