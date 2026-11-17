// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005c21d0 ?create@Creator@?$FactoryProduct@VBodyPosition@RBX@@VBodyMover@2@$1?sBodyPosition@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObjec: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/BodyMovers.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyPosition, RBX::BodyMover, RBX::sBodyPosition>::Creator::create() const;
