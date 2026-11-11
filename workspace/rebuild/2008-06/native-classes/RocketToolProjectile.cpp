// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
// >>> native-status (generated) -- do not edit >>>
// RocketToolProjectile | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by Espeon (deepseek:deepseek-flash)
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
