// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0045d950 ?create@Creator@?$FactoryProduct@VControllerService@RBX@@VInstance@2@$1?sControllerService@2@3PADA@RBX@@UBE?AV?$shared_p: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/UserController.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ControllerService, RBX::Instance, RBX::sControllerService>::Creator::create() const;
