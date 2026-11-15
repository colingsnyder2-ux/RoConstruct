#pragma once
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
		void ticklePrimitive(Primitive* p, int value);   // 005e9410

		// 005e91c0: contactManager (+0x84) -> ContactManager 0060cc50 (tail jump); donor name by call site
		// (Primitive setMassInertia 005e8000 / setCoordinateFrame 005e8200 after an extents change).
		void onPrimitiveExtentsChanged(Primitive* p);
		// 005e91d0: the assembly's primitives (005e5fc0 / 005e5fa0 iterator pair, ++ 00647640) each passed to
		// contactManager (+0x84) 0060cc50; donor name (only caller Primitive::setCoordinateFrame 005e8287).
		void onAssemblyExtentsChanged(Assembly* a);
		// 005e94a0 / 005e94e0: walk the stage chain from +0x88 to stage type 2 and call 0064cc40 / 0064ccf0; donor
		// names by call order (callers setDragging 005e8050, setAnchor 005e80d0 and 005e8140, anchored / not anchored).
		void onPrimitiveAddedAnchor(Primitive* p);
		void onPrimitiveRemovingAnchor(Primitive* p);
		SimJobStage& getSimJobStage();                     // 005e93b0
	};
}
