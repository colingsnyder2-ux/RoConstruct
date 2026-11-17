// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0044d560 ?create@Creator@?$FactoryProduct@VGameSettings@RBX@@VItem@GlobalSettings@2@$1?sGameSettings@2@3QBDB@RBX@@UBE?AV?$shared_: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/GameSettings.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::GameSettings, RBX::GlobalSettings::Item, RBX::sGameSettings>::Creator::create() const;
