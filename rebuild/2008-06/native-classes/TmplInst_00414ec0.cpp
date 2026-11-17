// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00414ec0 ?create@Creator@?$FactoryProduct@VLocalScript@RBX@@VScript@2@$1?sLocalScript@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObject@RBX: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "script/Script.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::LocalScript, RBX::Script, RBX::sLocalScript>::Creator::create() const;
