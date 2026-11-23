// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native RefPropDescriptorBatchB2008 (inactive): RefPropDescriptor<Class, ReturnType>::getRefValue / assignIDREF
// for the class pairs no other native unit instantiates (donor-free trial, rebuild/2008-06/out/donorfree/
// report-all-native.json). Same generic bodies as RefPropDescriptorGetRefValue.cpp (00585360) and
// RefPropDescriptorAssignIDREF.cpp (00585380); in the exe these bodies are identical-code folded across classes.
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "util/Handle.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Camera.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/Value.h"
#include "Network/Player.h"
#include "Network/Players.h"
#include "v8datamodel/Feature.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{
	namespace Reflection
	{
		template<typename Class, typename ReturnType>
		ReturnType* RefPropDescriptor<Class, ReturnType>::getValue(const DescribedBase* object) const
		{
			return getset->getValue(object);
		}

		template<typename Class, typename ReturnType>
		DescribedBase* RefPropDescriptor<Class, ReturnType>::getRefValue(const DescribedBase* object) const
		{
			return getValue(object);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::assignIDREF(DescribedBase* instance, const InstanceHandle& handle) const
		{
			boost::shared_ptr<Instance> target = handle.getTarget();
			// INFERRED: static_cast (no pointer adjustment, no RTTI): every instance is identical-code folded with the
			// <Instance, Instance> body 00585380, so the ReturnType* conversion emits no code.
			getset->setValue(instance, static_cast<ReturnType*>(target.get()));
		}

#define INSTANTIATE(C, R) \
		template DescribedBase* RefPropDescriptor<C, R>::getRefValue(const DescribedBase*) const; \
		template void RefPropDescriptor<C, R>::assignIDREF(DescribedBase*, const InstanceHandle&) const;
		INSTANTIATE(AutoJoint, PartInstance)
		INSTANTIATE(Camera, Instance)
		INSTANTIATE(Humanoid, PartInstance)
		INSTANTIATE(ModelInstance, PartInstance)
		INSTANTIATE(Mouse, PartInstance)
		INSTANTIATE(ObjectValue, Instance)
		INSTANTIATE(Network::Player, ModelInstance)
		INSTANTIATE(Network::Players, Network::Player)
		INSTANTIATE(VelocityMotor, Hole)
		INSTANTIATE(Workspace, Camera)
#undef INSTANTIATE
	}
}
