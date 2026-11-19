// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005c1cf0 ?create@Creator@?$FactoryProduct@VBodyForce@RBX@@VBodyMover@2@$1?sBodyForce@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObject@RBX@: explicit template instantiation (template_instances.py, byte-proved standalone)
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyForce, RBX::BodyMover, RBX::sBodyForce>::Creator::create() const;
