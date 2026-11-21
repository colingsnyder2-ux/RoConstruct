// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native RefPropDescriptor<Class, ReturnType>::setRefValue instances (inactive). reflection/reflection.h declares
// the member (and setValue) without a body; the original casts a non-null DescribedBase* to ReturnType* through
// boost::polymorphic_cast and stores it through the getset vtable (slot +0xc).
//   Humanoid/PartInstance 0049ab10, Camera/Instance 00491720, JointInstance/PartInstance 005a3d00,
//   ModelInstance/PartInstance 005e35f0, Instance/Instance 005cd810, Mouse/PartInstance 0060b9c0
#include <boost/cast.hpp>
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Mouse.h"
#include "humanoid/Humanoid.h"

namespace RBX
{
	namespace Reflection
	{
		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::setValue(DescribedBase* object, ReturnType* value) const
		{
			getset->setValue(object, value);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::setRefValue(DescribedBase* object, DescribedBase* value) const
		{
			ReturnType* typed = value ? boost::polymorphic_cast<ReturnType*>(value) : NULL;
			setValue(object, typed);
		}

		template void RefPropDescriptor<Humanoid, PartInstance>::setRefValue(DescribedBase*, DescribedBase*) const;
		template void RefPropDescriptor<Camera, Instance>::setRefValue(DescribedBase*, DescribedBase*) const;
		template void RefPropDescriptor<JointInstance, PartInstance>::setRefValue(DescribedBase*, DescribedBase*) const;
		template void RefPropDescriptor<ModelInstance, PartInstance>::setRefValue(DescribedBase*, DescribedBase*) const;
		template void RefPropDescriptor<Instance, Instance>::setRefValue(DescribedBase*, DescribedBase*) const;
		template void RefPropDescriptor<Mouse, PartInstance>::setRefValue(DescribedBase*, DescribedBase*) const;
	}
}
