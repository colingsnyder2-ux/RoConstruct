#pragma once
// >>> native-status (generated) -- do not edit >>>
// World2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 6a3720fb | roc native-status --write
// 2008-06 native RBX::World declaration (inactive). Minimal method surface needed by the
// native Joint family; bodies remain inactive and are not selected in the running player.
namespace RBX
{
	class Joint;
	class Primitive;
	class Assembly;
	class SimJobStage;

	class World
	{
	public:
		void onJointPrimitiveNulling(Joint* j, Primitive* p);
		void onJointPrimitiveSet(Joint* j, Primitive* p);
		void insertJoint(Joint* j);
		void removeJoint(Joint* j);
		void ticklePrimitive(Primitive* p, int value);
		void onPrimitiveExtentsChanged(Primitive* p);     // 005e91c0
		void onAssemblyExtentsChanged(Assembly* a);       // 005e91d0
		SimJobStage& getSimJobStage();                     // 005e93b0
		void onPrimitiveAddedAnchor(Primitive* p);        // 005e94a0
		void onPrimitiveRemovingAnchor(Primitive* p);     // 005e94e0
	};
}
