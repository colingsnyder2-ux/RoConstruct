// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_class_registry_native_family_dca4fea35dc48f15.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/object.h", "../roc_class_registry_native_header_a61a6f26f57e648b.cpp")
#pragma include_alias("util/Name.h", "../roc_member_name_const_header_435e0dbf905df038.cpp")
#pragma include_alias("reflection/member.h", "../roc_member_registry_native_header_9d65f5dc84cdc322.cpp")
#undef _RELEASEASSERT
#include "reflection/object.h"
template void RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::declare(RBX::Reflection::PropertyDescriptor*);
template void RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor>::declare(RBX::Reflection::SignalDescriptor*);
template void RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor>::declare(RBX::Reflection::FunctionDescriptor*);

namespace RBX { namespace Reflection {
static ClassDescriptor::ClassDescriptors& staticData2()
{
	static ClassDescriptor::ClassDescriptors result;
	return result;
}
static void initStaticData2()
{
	staticData2();
}

ClassDescriptor::ClassDescriptors& ClassDescriptor::allClasses()
{
	static boost::once_flag flag = BOOST_ONCE_INIT;
	boost::call_once(&initStaticData2, flag);
	return staticData2();
}

static bool compare2(const ClassDescriptor* a, const ClassDescriptor* b) { return a->name < b->name; }
		ClassDescriptor::ClassDescriptor(ClassDescriptor& base, const char* name)
			: Descriptor(name),
			  PropertyContainer(&base),
			  SignalContainer(&base),
			  FunctionContainer(&base),
			  derivedClasses(),
			  base(&base)
		{
			RBXASSERT(!lockedDown);

			{
				boost::recursive_mutex::scoped_lock lock(sync());
				ClassDescriptors::iterator bound = std::lower_bound(base.derivedClasses.begin(), base.derivedClasses.end(), this, compare2);
                base.derivedClasses.insert(bound, this);
                ClassDescriptors::iterator iter = allClasses().begin();
                while (iter != allClasses().end()) {
                    ClassDescriptor* desc = *iter;
                    if (Name::compare(this->name, desc->name) < 0) break;
                    ++iter;
                }
                allClasses().insert(iter, this);
			}
		}

} }
