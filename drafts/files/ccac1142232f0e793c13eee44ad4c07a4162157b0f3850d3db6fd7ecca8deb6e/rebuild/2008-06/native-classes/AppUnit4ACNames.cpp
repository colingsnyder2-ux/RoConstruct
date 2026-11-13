// 2008-06 native class-name template instances of the application range 004ac000..004b0000 (inactive). Verified by
// tests/record_native_app_unit4ac.py. All headers are read-only here.
//
// Name::callDoDeclare<sC>() (5 B, a tail jump to Name::doDeclare<sC>()) is inline in native util/Name.h; it is
// instantiated through Name::declare<sC>() for the seven 2008 joint class names of v8datamodel/JointInstance.h
// (char arrays, mangled 3PADA). The original rows 004ac320..004ac380 follow callDoDeclare<sLighting> 004ac310
// (lighting2008) and jump to the doDeclare rows 004ab160..004ab400 ("Snap", "Weld", "Glue", "Rotate", "RotateP",
// "RotateV", "Motor": 0083e040..0083e070); Name::declare<sC>() itself is inlined into its callers (005e3046 ...).
#include "v8datamodel/JointInstance.h"

namespace RBX
{
	template const Name& Name::declare<sSnap>();
	template const Name& Name::declare<sWeld>();
	template const Name& Name::declare<sGlue>();
	template const Name& Name::declare<sRotate>();
	template const Name& Name::declare<sRotateP>();
	template const Name& Name::declare<sRotateV>();
	template const Name& Name::declare<sMotor>();
}
