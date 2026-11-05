#include "v8datamodel/Explosion.h"
namespace RBX {
Reflection::BoundProp<G3D::Vector3,1> Explosion::propPosition("Position","Data",&Explosion::position,Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<float,1> Explosion::propBlastPressure("BlastPressure","Data",&Explosion::blastPressure,Reflection::PropertyDescriptor::STANDARD);
}
