// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00415150 ?create@Creator@?$FactoryProduct@VChangeHistoryService@RBX@@VInstance@2@$1?sChangeHistoryService@2@3PADA@RBX@@UBE?AV?$sh: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/ChangeHistoryService.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ChangeHistoryService, RBX::Instance, RBX::sChangeHistoryService>::Creator::create() const;
