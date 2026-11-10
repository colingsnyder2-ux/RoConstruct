#pragma once
// Declaration-only overlay used by tests/record_native_feature.py for the NATIVE_FEATURE_PENDING build of
// native-classes/Feature.cpp (copied as out/native-feature-pending/v8datamodel/JointInstance.h). It is the
// proposed 2008 RBX::JointInstance shape; the shared native-headers/v8datamodel/JointInstance.h is not edited.
// Only the class VelocityMotor derives from is declared.
//   RTTI       JointInstance vtable 0083e354 -> DescribedNonCreatable<JointInstance, Instance, sJointInstance>,
//              IRenderable +0x130, IJointOwner +0x140 (empty). sJointInstance mangles $1?sJointInstance@2@3QBDB
//              (a const char array; the shared header declares `extern char sJointInstance[]`, 3PADA).
//   fields     constructor 005e3870 (JointInstance(Joint*)): IRenderable +0x134/+0x138 = -1, +0x13c = 0;
//              `eh vector constructor iterator`(this+0x140, 8, 2) with weak_ptr ctor/dtor 005e27d0/005576e0, then
//              joint +0x150 = argument, part[0] (+0x140) / part[1] (+0x148) = weak references to the parts of the
//              joint primitives (PartInstance::fromPrimitive 00599f80, shared_from 00618a40). Size 0x154 (VelocityMotor
//              fields start at +0x154, constructor 0060bbb0). Destructor 005e2e10 destroys part[] the same way.
//   vtable     slot 3 askSetParent 005e3790, slot 4 onAncestorChanged 005e3a80 (VelocityMotor::onAncestorChanged
//              0060a0f0 calls it); IRenderable: shouldRender3dAdorn 005e27a0, render3dAdorn 005e2af0.
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include "v8world/Joint.h"
#include "v8tree/Instance.h"
#include "v8datamodel/PartInstance.h"
#include "util/IRenderable.h"
#include "reflection/reflection.h"

namespace RBX
{
	extern const char sJointInstance[];

	class JointInstance : public DescribedNonCreatable<JointInstance, Instance, sJointInstance>,
						  public IRenderable,
						  public IJointOwner
	{
	private:
		boost::weak_ptr<PartInstance> part[2];   // +0x140, +0x148

	protected:
		Joint* joint;                             // +0x150

		virtual bool askSetParent(const Instance* instance) const;   // 005e3790
		virtual void onAncestorChanged(const AncestorChanged& event); // 005e3a80
		virtual bool shouldRender3dAdorn() const;                     // 005e27a0
		virtual void render3dAdorn(Adorn* adorn);                     // 005e2af0

	public:
		JointInstance(Joint* joint);              // 005e3870
		~JointInstance();                         // 005e2e10
		Joint::JointType getJointType() const;
	};
}
