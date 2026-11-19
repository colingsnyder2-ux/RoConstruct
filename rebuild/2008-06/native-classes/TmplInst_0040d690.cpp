// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0040d690 ?create@Creator@?$FactoryProduct@VProperties@Metadata@Reflection@RBX@@VMembers@234@$1?sProperties@234@3PADA@RBX@@UBE?AV?: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "reflection/Metadata.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only (definition as in AppUnit400_2008Creators.cpp).
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Reflection::Metadata::Properties, RBX::Reflection::Metadata::Members, RBX::Reflection::Metadata::sProperties>::Creator::create() const;
