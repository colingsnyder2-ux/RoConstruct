// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0048f780 ?create@Creator@?$FactoryProduct@VClothing@RBX@@VCharacterAppearance@2@$1?sClothing@2@3QBDB@RBX@@UBE?AV?$shared_ptr@VObj: explicit template instantiation (template_instances.py, byte-proved standalone)
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Clothing, RBX::CharacterAppearance, RBX::sClothing>::Creator::create() const;
