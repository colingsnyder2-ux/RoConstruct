#include "humanoid/roc_Humanoid_2008.h"
namespace RBX {
Reflection::PropDescriptor<Humanoid, bool> propStrafe("Strafe", "Control", &Humanoid::getStrafe, &Humanoid::setStrafe, Reflection::PropertyDescriptor::STREAMING);
}
