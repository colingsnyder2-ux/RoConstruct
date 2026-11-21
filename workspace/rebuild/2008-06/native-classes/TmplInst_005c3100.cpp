// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005c3100 ?create@Creator@?$FactoryProduct@VSeat@RBX@@VPartInstance@2@$1?sSeat@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Seat.h"
#include "v8datamodel/PartInstance.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Seat, RBX::PartInstance, RBX::sSeat>::Creator::create() const;
