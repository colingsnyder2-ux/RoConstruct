// 2008-06 native class-name and class-descriptor template instances of the class-registration block 005bf800..005c09ff
// inside the application range 005bc000..005c8000 (inactive). Verified by tests/record_native_app_unit5bc_2008.py.
// All headers are read-only here.
//
// The block is the COMDAT run of the unit that holds the class-registration constructor 005c3ca0 (it calls every
// Described<C>::classDescriptor() below) and the Name static initializers 007f5650..007f5b50:
//   * Name::doDeclare<sC>() (101 B, `static const Name& n = declare(sC, -1)`) and Name::callDoDeclare<sC>() (5 B, a
//     tail jump), both inline in native util/Name.h, instantiated here through Name::declare<sC>();
//   * Reflection::Described<C, sC, B>::classDescriptor() (101 B, `static ClassDescriptor foo(B::classDescriptor(), sC)`),
//     inline in native reflection/reflection.h.
// Built here: the Explosion, FlagStandService and ObjectValue names and the Explosion, FlagStandService, Visit,
// JointInstance and ObjectValue descriptors (the other rows of the block are counted by the class receipts; the joint
// descriptors 005c3420..005c36c0 call JointInstance's 005c08d0 directly, which the native AutoJoint base does not give).
// >>> native-status (generated) -- do not edit >>>
// AppUnit5BC_2008Descriptors | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src a5e9388a | roc native-status --write
#include "v8datamodel/Explosion.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/Value.h"
#include "v8datamodel/Visit.h"
#include "v8datamodel/JointInstance.h"

namespace RBX
{
	template const Name& Name::declare<sExplosion>();
	template const Name& Name::declare<sFlagStandService>();
	template const Name& Name::declare<sObjectValue>();

	namespace Reflection
	{
		template ClassDescriptor& Described<Explosion, sExplosion, FactoryProduct<Explosion, Instance, sExplosion> >::classDescriptor();
		template ClassDescriptor& Described<FlagStandService, sFlagStandService, FactoryProduct<FlagStandService, Instance, sFlagStandService> >::classDescriptor();
		template ClassDescriptor& Described<Visit, sVisit, FactoryProduct<Visit, Instance, sVisit> >::classDescriptor();
		template ClassDescriptor& Described<JointInstance, sJointInstance, NonFactoryProduct<Instance, sJointInstance> >::classDescriptor();
		template ClassDescriptor& Described<ObjectValue, sObjectValue, FactoryProduct<ObjectValue, Instance, sObjectValue> >::classDescriptor();
	}
}
