#include "NativeHammerWorkerTrial.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Explosion.h"
#include "v8world/Primitive.h"
#include "util/Sound.h"
namespace RBX {
MouseCommand* HammerTool::onMouseDown(const UIEvent&) {
 if (partInstance) {
  boost::shared_ptr<Explosion> explosion=Creatable<Instance>::create<Explosion>();
  Explosion::propPosition.setValue(explosion.get(),partInstance->getCoordinateFrame().translation);
  Explosion::propBlastPressure.setValue(explosion.get(),0.0f);
  explosion->setParent(workspace);
  partInstance->setParent(NULL);
  ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(BOMB_SOUND);
 }
 return NULL;
}
}
