// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004b2b80 ?create@Creator@?$FactoryProduct@VRotate@RBX@@VJointInstance@2@$1?sRotate@2@3QBDB@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@: explicit template instantiation (template_instances.py, byte-proved standalone)
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Rotate, RBX::JointInstance, RBX::sRotate>::Creator::create() const;
