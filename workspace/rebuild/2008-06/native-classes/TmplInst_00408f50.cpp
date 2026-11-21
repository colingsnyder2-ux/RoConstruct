// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00408f50 ?create@Creator@?$FactoryProduct@VCRenderSettings@@VItem@GlobalSettings@RBX@@$1?sRenderSettings@@3PADA@RBX@@UBE?AV?$shar: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "CRenderSettings.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<CRenderSettings, RBX::GlobalSettings::Item, sRenderSettings>::Creator::create() const;
