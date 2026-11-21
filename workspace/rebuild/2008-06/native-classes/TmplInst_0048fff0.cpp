// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0048fff0 ?create@Creator@?$FactoryProduct@VBodyColors@RBX@@VCharacterAppearance@2@$1?sBodyColors@2@3QBDB@RBX@@UBE?AV?$shared_ptr@: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/BodyColors.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>::Creator::create() const;
