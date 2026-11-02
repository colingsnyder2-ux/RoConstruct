#include "NativeLaserTrial.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Explosion.h"
#include "util/Sound.h"
#include "humanoid/Humanoid.h"
namespace RBX {

MouseCommand* LaserTool::onMouseDown(const UIEvent& input) {
 PartInstance* torso=Humanoid::getLocalHeadFromContext(workspace);
 if (torso) {
  origin=torso->getCoordinateFrame().translation;
  G3D::Vector3 hit(0,0,0);
  PartInstance* part=getPart(input,NULL,hit);
  if (part) {
   boost::shared_ptr<Explosion> explosion=Creatable<Instance>::create<Explosion>();
   Explosion::propPosition.setValue(explosion.get(),hit);
   Explosion::propBlastPressure.setValue(explosion.get(),0.0f);
   explosion->setParent(workspace);
   if (!part->getPartLocked()) part->remove();
   ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(SNAP_SOUND);
  }
  frames=4;
 }
 return this;
}
}

