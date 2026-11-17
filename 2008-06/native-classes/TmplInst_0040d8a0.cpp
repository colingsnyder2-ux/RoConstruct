// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0040d8a0 ?create@Creator@?$FactoryProduct@VAuthoringSettings@@VItem@GlobalSettings@RBX@@$1?sAuthoringSettings@@3PADA@RBX@@UBE?AV?: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "AuthoringSettings.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<AuthoringSettings, RBX::GlobalSettings::Item, sAuthoringSettings>::Creator::create() const;
