// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native RBX::InstanceHandle::linkTo (inactive). Flags copied from RefPropDescriptorAssignIDREF.cpp (the
// InstanceHandle reference-property unit). Identity: registry
// ?linkTo@InstanceHandle@RBX@@QAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z 00594d60 (thiscall, ret 8: shared_ptr by
// value), neighbours newGuidRegistryCriticalSection 00594c10, boost::mutex rows 00594c90..00594d40 and
// shared_ptr<Instance>::_internal_less 00594de0 (InstanceHandle::operatorLess). Declaration: util/Handle.h.
#include "util/Handle.h"

namespace RBX
{
	// 00594d60: px copied to +0x00, shared_count assignment 004025b0 into +0x04, then the by-value argument released
	// (use_count at +4, weak_count at +8, sp_counted_base slots 1 dispose / 2 destroy). Donor body: util/Handle.cpp.
	void InstanceHandle::linkTo(boost::shared_ptr<Instance> target)
	{
		this->target = target;
	}
}
