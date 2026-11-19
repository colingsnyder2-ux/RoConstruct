// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0048f2a0 ?create@Creator@?$FactoryProduct@VSpawnerService@RBX@@VInstance@2@$1?sSpawnerService@2@3QBDB@RBX@@UBE?AV?$shared_ptr@VOb: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/SpawnerService.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>::Creator::create() const;
