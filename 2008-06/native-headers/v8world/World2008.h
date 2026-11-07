#pragma once
// >>> native-status (generated) -- do not edit >>>
// World2008 | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 6a3720fb | roc native-status --write
// 2008-06 native RBX::World declaration (inactive). Minimal method surface needed by the
// native Joint family; bodies remain inactive and are not selected in the running player.
namespace RBX
{
	class Joint;
	class Primitive;

	class World
	{
	public:
		void onJointPrimitiveNulling(Joint* j, Primitive* p);
		void onJointPrimitiveSet(Joint* j, Primitive* p);
		void insertJoint(Joint* j);
		void removeJoint(Joint* j);
		void ticklePrimitive(Primitive* p, int value);
	};
}