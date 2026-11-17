// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0048e810 ?create@Creator@?$FactoryProduct@VHopperBin@RBX@@VBackpackItem@2@$1?sHopperBin@2@3QBDB@RBX@@UBE?AV?$shared_ptr@VObject@R: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Hopper.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>::Creator::create() const;
