// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004b2910 ?create@Creator@?$FactoryProduct@VGlue@RBX@@VJointInstance@2@$1?sGlue@2@3QBDB@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boos: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/JointInstance.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Glue, RBX::JointInstance, RBX::sGlue>::Creator::create() const;
