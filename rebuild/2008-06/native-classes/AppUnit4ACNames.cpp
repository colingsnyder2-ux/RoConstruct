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
