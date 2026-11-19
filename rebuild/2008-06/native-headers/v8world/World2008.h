#pragma once
// 2008-06 native RBX::World declaration (inactive). Minimal method surface needed by the
// native Joint family; bodies remain inactive and are not selected in the running player.
namespace RBX
{
	class Joint;
	class Primitive;
	class Assembly;
	class SimJobStage;
	class Kernel;
	class Contact;

	class World
	{
	public:
		// EnumDesc<World::EThrottle> 00564be0 ("EnviromentalPhysicsThrottle") registers DefaultAuto, Disabled, Random and
		// Always in this order; donor names (generated settings-items-pending World.h of tests/record_native_settings_items.py).
		enum EThrottle
		{
			DefaultAuto,
			Disabled,
			Random,
			Always
		};
		// The 4-byte global 0x97ac54: DebugSettings::getEnvironmentalThrottle 005631b0 returns it, and the setter 00565d40
		// compares, stores it and raises prop_PhysicsEnviromentalThrottle (0x9744f4).
		static EThrottle environmentalThrottle;

		// 005e9520: walks the stage chain from +0x88 to stage type 2 and tail-jumps to 0064cad0; donor name (only caller
		// ContactManager::getHit 0060d6e8, as donor ContactManager::getHit calls world->update()).
		void update();
		// 005e9260: passes the contact to the first stage (+0x88, vtable +0x10), then ++(+0xe8); donor name (callers
		// ContactManager::onNewPair 0060d8c8 and onPrimitiveGeometryTypeChanged 0060d9c1).
		void insertContact(Contact* c);
		// 005e9280: first stage (+0x88, vtable +0x14), deletes the contact (virtual destructor), then --(+0xe8)
		// (caller ContactManager::onPrimitiveGeometryTypeChanged 0060d995); donor name.
		void destroyContact(Contact* c);

		// INFERRED: decorated registry symbols ?onPrimitiveCanCollideChanged@World@RBX@@QAEXPAVPrimitive@2@@Z (00732a20/00732a40/
		// 007356f0 are the same-name bodies), ?step@World@RBX@@QAEMM@Z 005e9fd0 and 005e9190 onPrimitiveContactParametersChanged.
		void onPrimitiveCanCollideChanged(Primitive* p);
		void onPrimitiveContactParametersChanged(Primitive* p);
		float step(float desiredInterval);

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
		// 005e9150 (13 bytes): the first stage (+0x88) -> IStage::getKernel (slot 3, tail jump). Reference return as the
		// definition in native-classes/AppUnit5E8_2008World.cpp and the donor v8world/World.h (callers Humanoid /
		// BodyMover::onAncestorChanged 005db560 / 006308f0 use it with Kernel::insert/removeConnector2ndPass).
		Kernel& getKernel();
		// 005e9230 (11 bytes): contactManager (+0x84) -> ContactManager::onPrimitiveGeometryTypeChanged 0060d8e0 (tail jump);
		// donor name (only caller the Primitive method 005e86f0, call at 005e874b).
		void onPrimitiveGeometryTypeChanged(Primitive* p);
	};
}
