// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00578480 ?create@Creator@?$FactoryProduct@VTool@RBX@@VBackpackItem@2@$1?sTool@2@3QBDB@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Tool.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Tool, RBX::BackpackItem, RBX::sTool>::Creator::create() const;
