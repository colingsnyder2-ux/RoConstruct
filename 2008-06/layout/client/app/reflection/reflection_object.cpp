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
