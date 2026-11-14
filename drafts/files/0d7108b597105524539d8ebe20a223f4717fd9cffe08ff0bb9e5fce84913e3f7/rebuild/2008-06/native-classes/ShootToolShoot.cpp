// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// ShootToolShoot | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by coldek (deepseek:deepseek-chat)
// <<< native-status | src 84b3d4cf | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "humanoid/Humanoid.h"
#include "util/Sound.h"
namespace RBX {
void ShootTool::shoot(const UIEvent& input) {
 remaining=delay;
 PartInstance* head=Humanoid::getLocalHeadFromContext(workspace);
 if (head) {
  if (!projectile) projectile=createProjectile();
  // 0063e890: the original calls 005a1680, a cdecl wrapper that only forwards to the folded
  // shared_static_cast body 004a2070 -- the release shape of boost 1.34 shared_polymorphic_downcast
  // (BOOST_ASSERT compiled out, then shared_static_cast). Rejected: shared_static_cast called directly
  // (body IDENTICAL, but its call bound 004a2070 instead of the original 005a1680).
  boost::shared_ptr<PartInstance> part=boost::shared_polymorphic_downcast<PartInstance>(projectile->clone());
  part->setParent(workspace);
  part->getPrimitive()->setPV(launch(input,head->getCoordinateFrame()));
  ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(static_cast<SoundType>(getShootSound()));
 }
}
}
