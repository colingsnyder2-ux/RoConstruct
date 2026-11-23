#pragma once
// 2008-06 native RBX::World declaration (inactive). Minimal method surface needed by the
// native Joint family; bodies remain inactive and are not selected in the running player.
namespace G3D
{
	template <class T> class Array;   // computeFallen 005e9c40 parameter (G3D/Array.h declares it the same way)
}

namespace RBX
{
	class Joint;
	class Primitive;
	class Assembly;
	class SimJobStage;
	class Kernel;
	class Contact;
}

// NATIVE_WORLD_LAYOUT (opt-in, defined by a unit before including this header): the 2008 data layout and the four
// Notifier bases, for bodies that touch World fields directly (native-classes/RBXWorldRecovery_005e9170.cpp). Units
// that only call World methods keep the field-less declaration (same member functions, same decorated names).
// Layout read from World() 005ea920 (and the bodies cited per field):
//   bases    Notifier<World, AutoJoin> +0x0, <AutoDestroy> +0x20, <AssemblyPhysicsOn> +0x40, <AssemblyPhysicsOff> +0x60
//            (vtables 0083f8d8 / 0083f8c8 / 0083f8b8 / 0083f8a8; createJoints 005ea4d0 raises AutoJoin through `this`,
//            destroyJoints 005ea3f0 raises AutoDestroy through `this + 0x20`, 005e9b80 uses +0x40 / +0x60).
//   +0x80 float (ctor [008163a4]), +0x84 contactManager (new 0x14, ContactManager(World*) 0060d260), +0x88 first stage
//   (new 0x10, CleanStage(NULL, this) 0064a310), +0x8c touch / +0x98 touchOther (G3D::Array: data, num, numAllocated),
//   +0xa4 inStepCode, +0xa5 inJointNotification (createJoints / destroyJoints set and clear it around the raise),
//   +0xa8 worldStepId, +0xac primitives (G3D::Array shape), +0xb8 a second G3D::Array (zeroed the same way, absent
//   from the donor), +0xc4 breakableJoints (std::set, _Tree ctor 0064b2a0, 0x20 bytes), +0xe4 numJoints, +0xe8
//   numContacts (insertContact 005e9260), +0xec numLinkCalls (createJoints `inc [esi+0xec]`), +0xf0 tempPrimitives
//   (createJoints: resize(0, false) 00599a70, data +0xf0 / num +0xf4), +0xfc.. the Profiler objects (new 0xc048).
#ifdef NATIVE_WORLD_LAYOUT
#include <set>
#include <G3D/Array.h>
#include "util/Events.h"
// The primitives member is the donor IndexArray<Primitive, &Primitive::worldIndexFunc> (same 0xc G3D::Array layout):
// the unit includes v8world/Primitive2008.h before this header, so the member pointer names a complete Primitive.
#include "util/IndexArray.h"
namespace RBX
{
	class IStage;
	class ContactManager;

	// Donor engine-world v8world/World.h event types (same declarations).
	struct AutoJoin
	{
		Joint* joint;
		AutoJoin(Joint* j) : joint(j) {}
	};

	struct AutoDestroy
	{
		Joint* joint;
		AutoDestroy(Joint* j) : joint(j) {}
	};

	struct AssemblyPhysicsOn { Primitive* primitive; };
	struct AssemblyPhysicsOff { Primitive* primitive; };
}
#endif

namespace RBX
{
	class World
#ifdef NATIVE_WORLD_LAYOUT
		: public Notifier<World, AutoJoin>, public Notifier<World, AutoDestroy>,
		  public Notifier<World, AssemblyPhysicsOn>, public Notifier<World, AssemblyPhysicsOff>
#endif
	{
#ifdef NATIVE_WORLD_LAYOUT
	private:
		float throttlePercentage;                         // +0x80 (donor-analog name, as engine-world World.h)
		ContactManager* contactManager;                   // +0x84
		IStage* jointStage;                               // +0x88 (2008: a CleanStage)
		G3D::Array<Primitive*> touch;                     // +0x8c
		G3D::Array<Primitive*> touchOther;                // +0x98
		bool inStepCode;                                  // +0xa4
		bool inJointNotification;                         // +0xa5
		int worldStepId;                                  // +0xa8
		// +0xac: insertPrimitive 005e98f0 stores the array size to Primitive +0x50 before Array::append 0059a190 (fastAppend);
		// removePrimitive 005ea8b0 moves the last element into the slot and resizes (fastRemove).
		IndexArray<Primitive, &Primitive::worldIndexFunc> primitives;   // +0xac
		G3D::Array<Primitive*> unknownB8;                 // +0xb8 INFERRED: element type and name; the ctor zeroes an Array here
		std::set<Joint*> breakableJoints;                 // +0xc4
		int numJoints;                                    // +0xe4
		int numContacts;                                  // +0xe8
		int numLinkCalls;                                 // +0xec
		G3D::Array<Primitive*> tempPrimitives;            // +0xf0

		// 005ea4d0 / 005ea3f0: registry decorated names ?createJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@... and
		// ?destroyJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@... (private, as in the donor World.h).
		void createJoints(Primitive* p, std::set<Primitive*>* ignoreGroup);
		void destroyJoints(Primitive* p, std::set<Primitive*>* ignoreGroup);
		// 005e9e00 (registry placeholder func_005e9e00; openrbx World::doBreakJoints, private): walks breakableJoints
		// (+0xc4), and for each joint in the kernel (IPipelined stage type 7) that isBroken (slot 7) raises AutoDestroy on
		// the +0x20 base (005e99d0) under inJointNotification (+0xa5). Caller World::step 005e9fd0.
		void doBreakJoints();
		// INFERRED: placeholder names (no name evidence; registry func_005e9550 / func_005e9bb0). Private World::step
		// helpers (callers World::step 005e9fd0 / 005ea193): both walk primitives (+0xac / +0xb0), take getAssembly
		// 005e7570 and the 2008 moving test (SleepInfo +0x18 non-NULL, state 3 / 1 / 2), then refresh the cached
		// getCoordinateFrame 005e82c0 / getFastFuzzyExtents 005e7a50. 005e9550 (`ret 4`, its argument is unread): moving
		// primitives only through their assembly root, fuzzy extents only when not moving. 005e9bb0: resize(0) of +0xb8
		// (00599a70), then every moving primitive appended to it (0059a190), its frame unless it is the root, its extents.
		void sub_005e9550(int unused);
		void sub_005e9bb0();
#endif
	public:
		// 005e98f0 / 005ea8b0 (registry placeholders func_005e98f0 / func_005ea8b0; openrbx World::insertPrimitive /
		// removePrimitive; callers PartInstance::onAncestorChanged 0059ab3a / 0059ab21). Bodies in
		// native-classes/RBXWorldRecovery_005e9170.cpp.
		void insertPrimitive(Primitive* p);
		void removePrimitive(Primitive* p);
		// 005e98c0 (registry placeholder func_005e98c0; `ret 8`): appends both primitives to touch (+0x8c) / touchOther
		// (+0x98) with Array::append 0059a190; donor name (caller the Primitive.cpp newTouch 005e7519). Body in
		// native-classes/AppUnit5E8_2008World.cpp.
		void onPrimitiveTouched(Primitive* touchP, Primitive* touchOtherP);
		// 005e9c40 (registry placeholder func_005e9c40; `ret 4`, caller Workspace::step 005a2580; openrbx World::computeFallen):
		// the first stage's findStage(5) (SleepStage), its awake set (+0x120), and every primitive of an assembly whose
		// root primitive frame translation.y is below [0083f8a0] whose own frame is also below it, appended to fallen.
		void computeFallen(G3D::Array<Primitive*>& fallen) const;
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
		// 005e9b80 (40 bytes, `ret 8`; registry placeholder func_005e9b80): raises the +0x40 (on) or +0x60 (off) notifier
		// (005e9a60 / 005e9af0) with the assembly's root primitive ([[a+0x24]+0x1c]), i.e. the donor AssemblyPhysicsOn /
		// AssemblyPhysicsOff events of engine-world v8world/World.h. Callers SleepStage::onAssemblyAdded 0064aff0 (true)
		// and onAssemblyRemoving 0064b0a0 (false). INFERRED: name (no donor counterpart; the donor raises inline).
		void notifyAssemblyPhysics(Assembly* a, bool on);
	};
}
