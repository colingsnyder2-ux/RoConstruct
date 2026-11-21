// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0041ecb0 ?create@Creator@?$FactoryProduct@VSpecialShape@RBX@@VInstance@2@$1?sSpecialShape@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObject: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/SpecialShape.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::SpecialShape, RBX::Instance, RBX::sSpecialShape>::Creator::create() const;
