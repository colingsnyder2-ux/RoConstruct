// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00490580 ?create@Creator@?$FactoryProduct@VTimerService@RBX@@VInstance@2@$1?sTimerService@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObject: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/TimerService.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::TimerService, RBX::Instance, RBX::sTimerService>::Creator::create() const;
