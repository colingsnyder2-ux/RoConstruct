#include "humanoid/roc_Humanoid_2008.h"
namespace RBX {
extern Reflection::PropDescriptor<Humanoid, bool> propStrafe;
bool Humanoid::getStrafe() const { return strafe; }
void Humanoid::setStrafe(bool value) {
    if (strafe != value) { strafe = value; raisePropertyChanged(propStrafe); }
}
}
