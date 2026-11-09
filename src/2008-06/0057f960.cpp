// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_92001885dd6c4dcc.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_espeon_nativeinstanceguidportablea1682bda32c99cd2.cpp")
#include "v8tree/Instance.h"
#include "reflection/property.h"
// 2008-06 0057f960 / 0057f810: bool-property functors applied to selected instances
// (std::for_each over shared_ptr<Instance>), authentic reflection iterators.
namespace RBX {
// 2008 PropertyIterator exposes its descriptor like ConstIterator::getDescriptor() (**iter);
// this view has the header Iterator's layout (instance, CollectionType::const_iterator).
struct PropertyIteratorView
{
	Reflection::DescribedBase* instance;
	Reflection::PropertyContainer::CollectionType::const_iterator iter;
	const Reflection::PropertyDescriptor& getDescriptor() const { return **iter; }
};
static inline const Reflection::PropertyDescriptor& descriptorOf(const Reflection::PropertyIterator& iter)
{
	return reinterpret_cast<const PropertyIteratorView&>(iter).getDescriptor();
}
class SetBoolPropertyFunctor
{
	const Name& name;
	bool value;
public:
	SetBoolPropertyFunctor(const Name& name, bool value) : name(name), value(value) {}
	void operator()(boost::shared_ptr<Instance> instance);
};
void SetBoolPropertyFunctor::operator()(boost::shared_ptr<Instance> instance)
{
	Reflection::PropertyIterator iter = instance->findProperty(name);
	if (iter != instance->properties_end())
	{
		if (dynamic_cast<const Reflection::TypedPropertyDescriptor<bool>*>(&descriptorOf(iter)))
		{
			if ((*iter).getValue<bool>() != value)
				(*iter).setValue(value);
		}
	}
}
bool hasTrueBoolProperty(const Name& name, boost::shared_ptr<Instance> instance)
{
	Reflection::PropertyIterator iter = instance->findProperty(name);
	if (iter != instance->properties_end())
	{
		if (dynamic_cast<const Reflection::TypedPropertyDescriptor<bool>*>(&descriptorOf(iter)))
		{
			if ((*iter).getValue<bool>())
				return true;
		}
	}
	return false;
}
}
