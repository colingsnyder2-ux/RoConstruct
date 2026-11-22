// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native RefPropDescriptor<Class, ReturnType>::assignIDREF (inactive). reflection/reflection.h declares the
// IIDREF override without a body. The override is introduced by the non-primary base IIDREF, so MSVC passes the IIDREF
// subobject as this: getset is the word right after the IIDREF vftable (+4). The body copies the handle's target
// (InstanceHandle::getTarget, called out of line at 004915b0, identical-code folded with slot_base::get_data), then
// stores target.get() through the GetSet vftable slot 3 (+0xc, setValue(DescribedBase*, ReturnType* const&)) and
// releases the shared_ptr copy (ret 8).
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "util/Handle.h"

namespace RBX
{
	namespace Reflection
	{
		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::assignIDREF(DescribedBase* instance, const InstanceHandle& handle) const
		{
			boost::shared_ptr<Instance> target = handle.getTarget();
			getset->setValue(instance, target.get());
		}

		// 00585380 ?assignIDREF@?$RefPropDescriptor@VInstance@RBX@@V12@@Reflection@RBX@@UBEXPAVDescribedBase@23@ABVInstanceHandle@3@@Z
		template void RefPropDescriptor<Instance, Instance>::assignIDREF(DescribedBase*, const InstanceHandle&) const;
	}
}
