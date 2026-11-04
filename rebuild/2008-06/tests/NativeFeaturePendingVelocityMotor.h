#pragma once
// Declaration-only overlay used by tests/record_native_feature.py to verify MotorFeature::join
// (NATIVE_FEATURE_PENDING). Copied as out/native-feature-pending/v8datamodel/VelocityMotor.h.
// Not a recovery of VelocityMotor (same original unit, outside this lease): only what join calls.
//   VelocityMotor RTTI (FactoryProduct dtor 00609af0 vtables): DescribedCreatable<VelocityMotor,
//     JointInstance, sVelocityMotor> (name mangled $1?sVelocityMotor@2@3QBDB: const char array).
//   join 0060ca00 calls Creatable<Instance>::create<VelocityMotor> 005804a0 (sret shared_ptr),
//     VelocityMotor::setHole 0060c400 (thiscall, one Hole* argument) and Instance::setParent 0055a8f0.
//   Constructor 0060bbb0 and destructor 0060a650 are declared only so the class template bases are not
//   instantiated with JointInstance's missing default constructor.
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Feature.h"

namespace RBX
{
	extern const char sVelocityMotor[];

	class VelocityMotor : public DescribedCreatable<VelocityMotor, JointInstance, sVelocityMotor>
	{
	public:
		VelocityMotor();               // 0060bbb0
		virtual ~VelocityMotor();      // 0060a650
		void setHole(Hole* value);
	};
}
