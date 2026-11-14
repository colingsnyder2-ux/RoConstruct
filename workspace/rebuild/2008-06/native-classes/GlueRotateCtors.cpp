// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Glue/Rotate/RotateP/RotateV/Motor constructors from the 005e4000 unit. Byte-exact: Glue() 005e49a0, Rotate() 005e4ad0 and the
// (Joint*) constructors 005e4920/005e4a60/005e4b90/005e4d30 (identical bodies, one per class). Unlike Snap/Weld these set no
// name in the constructor. The RotateP()/RotateV()/Motor() defaults are not recovered here.
#include "v8datamodel/JointInstance.h"
#include "v8world/GlueJoint.h"
#include "v8world/RotateJoint.h"

namespace RBX {
Glue::Glue(Joint* joint) : DescribedCreatable<Glue, AutoJoint, sGlue>(joint) { }
Glue::Glue() : DescribedCreatable<Glue, AutoJoint, sGlue>(new GlueJoint()) { }
Rotate::Rotate(Joint* joint) : DescribedCreatable<Rotate, AutoJoint, sRotate>(joint) { }
Rotate::Rotate() : DescribedCreatable<Rotate, AutoJoint, sRotate>(new RotateJoint()) { }
RotateP::RotateP(Joint* joint) : DescribedCreatable<RotateP, AutoJoint, sRotateP>(joint) { }
RotateV::RotateV(Joint* joint) : DescribedCreatable<RotateV, AutoJoint, sRotateV>(joint) { }
Motor::Motor(Joint* joint) : DescribedCreatable<Motor, AutoJoint, sMotor>(joint) { }
}
