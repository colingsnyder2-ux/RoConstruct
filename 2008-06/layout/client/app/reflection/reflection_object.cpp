// =============================================================================
// reflection_object.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/reflection/reflection_object.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "reflection/reflection.h"
#include "reflection/object.h"

namespace RBX
{
	namespace Reflection
	{
		ClassDescriptor::ClassDescriptor()
			: Descriptor("<<<ROOT>>>"),
			  PropertyContainer(NULL),
			  SignalContainer(NULL),
			  FunctionContainer(NULL),
			  derivedClasses(),
			  base(NULL)
		{
		}

		bool MemberDescriptor::isMemberOf(const ClassDescriptor& classDescriptor) const
		{
			const ClassDescriptor* p = &classDescriptor;
			do
			{
				if (p == &owner)
					return true;
				p = p->getBase();
			}
			while (p != &ClassDescriptor::rootDescriptor());

			return false;
		}

		bool MemberDescriptor::isMemberOf(const DescribedBase* instance) const
		{
			return isMemberOf(instance->getDescriptor());
		}
	}
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class std::_Vector_const_iterator<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> >;
template class std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> >;
template class std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> >;
template class std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> >;
template class std::_Vector_const_iterator<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> >;
template class std::_Vector_iterator<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> >;
template class std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> >;
template class std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> >;
template class std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> >;
template class std::_Vector_iterator<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> >;
template class std::_Vector_iterator<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> >;

// ROOT ctor 00570820 is in AppUnit570_2008Reflection.cpp. INFERRED: no address recorded yet for these three.

namespace RBX
{
	namespace Reflection
	{
		ClassDescriptor::ClassDescriptor(ClassDescriptor& base, const char* name)
			: Descriptor(name),
			  PropertyContainer(&base),
			  SignalContainer(&base),
			  FunctionContainer(&base),
			  derivedClasses(),
			  base(&base)
		{
			{
				boost::recursive_mutex::scoped_lock lock(sync());
				base.derivedClasses.push_back(this);
			}
		}

		bool ClassDescriptor::operator==(const ClassDescriptor& other) const
		{
			return this == &other;
		}

		bool ClassDescriptor::operator!=(const ClassDescriptor& other) const
		{
			return this != &other;
		}
	}
}
