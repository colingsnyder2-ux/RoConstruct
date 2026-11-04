#pragma once
// Declaration-only overlay (copied as out/native-team-pending/v8datamodel/ModelInstance.h by
// tests/record_native_team.py). The native ModelInstance.h pulls donor v8datamodel/Camera.h, which
// does not compile with the 2008 const-char-array DescribedCreatable. Teams only calls
// Instance::findFirstChildOfType on the character, so this keeps just the original first base:
// RTTI 00830dc4 .?AVModelInstance@RBX@@ -> DescribedCreatable<ModelInstance, PVInstance, sModel>
// (sModel mangled 3PADA), PVInstance/Instance at offset 0.
#include "v8datamodel/PVInstance.h"

namespace RBX
{
	extern char sModel[];
	class ModelInstance : public DescribedCreatable<ModelInstance, PVInstance, sModel>
	{
	};
}
