// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native RefPropDescriptor<Class, ReturnType>::getRefValue instance (inactive). reflection/reflection.h declares
// getValue and getRefValue without a body; flags line copied from the sibling RefPropDescriptorTemplates2008.cpp
// (setRefValue instances). getValue is the getset vtable slot 2 (+8) call, inlined; the ReturnType* result converts
// to DescribedBase* (+0x14 inside Instance, NULL-preserving).
#include "reflection/reflection.h"
#include "v8tree/Instance.h"

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

		// 00585360 ?getRefValue@?$RefPropDescriptor@VInstance@RBX@@V12@@Reflection@RBX@@UBEPAVDescribedBase@23@PBV423@@Z
		// (registry identity-closure; the same 30-byte body fills slot getRefValue of many RefPropDescriptor vtables,
		// 00821b84, 008228bc, 0082d798, ..., identical-code folded).
		template DescribedBase* RefPropDescriptor<Instance, Instance>::getRefValue(const DescribedBase*) const;
	}
}
