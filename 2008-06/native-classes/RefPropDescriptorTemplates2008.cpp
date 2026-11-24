// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native RefPropDescriptor<Class, ReturnType>::setRefValue instances (inactive). reflection/reflection.h declares
// the member (and setValue) without a body; the original casts a non-null DescribedBase* to ReturnType* through
// boost::polymorphic_cast and stores it through the getset vtable (slot +0xc).
//   Humanoid/PartInstance 0049ab10, Camera/Instance 00491720, JointInstance/PartInstance 005a3d00,
//   ModelInstance/PartInstance 005e35f0, Instance/Instance 005cd810, Mouse/PartInstance 0060b9c0
// Batch 49 correction from the RTTI of the vtables that hold each address in slot 13 (setRefValue):
//   0049ab10 vtable 0082288c = RefPropDescriptor<Network::Players, Network::Player>; 00491720 vtable 00821b50 =
//   RefPropDescriptor<Network::Player, ModelInstance>; 005a3d00 vtable 00833ae0 = RefPropDescriptor<Workspace, Camera>;
//   0060b9c0 vtable 00842fbc = RefPropDescriptor<VelocityMotor, Hole>. The first four labels above are therefore not
//   the instances at those addresses. Each body calls an out-of-line polymorphic_cast<T*> (00492a90 for Player,
//   004914f0 for ModelInstance).
#include "util/NativeContentProvider.h"   // first: renames the donor util/ContentProvider.h class (PlayerCharacter.cpp pattern)
#include <boost/cast.hpp>
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Mouse.h"
#include "humanoid/Humanoid.h"
#include "Network/Player.h"
#include "Network/Players.h"

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
		// 0049ab10: vtable 0082288c slot 13 (RTTI RefPropDescriptor<Network::Players, Network::Player>, Players::propLocalPlayer
		// 00970388); polymorphic_cast<Player*> 00492a90 (__RTDynamicCast to .?AVPlayer@Network@RBX@@ 00937460).
		template void RefPropDescriptor<Network::Players, Network::Player>::setRefValue(DescribedBase*, DescribedBase*) const;
		// 00491720: vtable 00821b50 slot 13 (RTTI RefPropDescriptor<Network::Player, ModelInstance>, Player prop_Character
		// 0096fe70); polymorphic_cast<ModelInstance*> 004914f0.
		template void RefPropDescriptor<Network::Player, ModelInstance>::setRefValue(DescribedBase*, DescribedBase*) const;
	}
}
