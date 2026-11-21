// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00490260 ?create@Creator@?$FactoryProduct@VSkin@RBX@@VCharacterAppearance@2@$1?sSkin@2@3QBDB@RBX@@UBE?AV?$shared_ptr@VObject@RBX@: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Clothing.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>::Creator::create() const;
