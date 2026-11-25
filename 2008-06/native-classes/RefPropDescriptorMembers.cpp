// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
//
// RBX::Reflection::RefPropDescriptor<Class, ReturnType> member bodies that reflection/reflection.h only declares.
// Every RefPropDescriptor instance's isReadOnly (11 classes on the File->New path: Camera, Workspace, ModelInstance,
// Humanoid, ...) ran as a `return 0` placeholder in the donor-free link because no source defined these template
// members. Out-of-class template definitions here are harvested by work/donorfree-route/tmplinst.py --rbx and
// instantiated per class; they are not a class swap and carry no match claim.
//
// INFERRED: same accessor pattern as EnumPropDescriptor in reflection.h (every typed descriptor forwards to its
// getset object: isReadOnly -> getset->isReadOnly(), get/set -> getset->getValue/setValue). getRefValue/setRefValue
// adapt the typed pointer to the DescribedBase* interface RefPropertyDescriptor declares. readValue/writeValue
// (XML referents through IReferenceBinder) are NOT here: their protocol needs the original bodies.
#include "reflection/reflection.h"

namespace RBX
{
	namespace Reflection
	{
		template<typename Class, typename ReturnType>
		bool RefPropDescriptor<Class, ReturnType>::isReadOnly() const
		{
			return getset->isReadOnly();
		}

		template<typename Class, typename ReturnType>
		ReturnType* RefPropDescriptor<Class, ReturnType>::getValue(const DescribedBase* instance) const
		{
			return getset->getValue(instance);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::setValue(DescribedBase* instance, ReturnType* value) const
		{
			getset->setValue(instance, value);
		}

		template<typename Class, typename ReturnType>
		bool RefPropDescriptor<Class, ReturnType>::equalValues(const DescribedBase* a, const DescribedBase* b) const
		{
			return getValue(a) == getValue(b);
		}

		template<typename Class, typename ReturnType>
		DescribedBase* RefPropDescriptor<Class, ReturnType>::getRefValue(const DescribedBase* instance) const
		{
			return getValue(instance);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::setRefValue(DescribedBase* instance, DescribedBase* value) const
		{
			setValue(instance, dynamic_cast<ReturnType*>(value));
		}
	}
}
