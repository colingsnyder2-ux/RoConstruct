// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00578210 ?create@Creator@?$FactoryProduct@VLocalBackpack@RBX@@VRelativePanel@2@$1?sLocalBackpack@2@3QBDB@RBX@@UBE?AV?$shared_ptr@: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "LocalBackpack2008/LocalBackpack2008.h"
#include "gui/Gui.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::LocalBackpack, RBX::RelativePanel, RBX::sLocalBackpack>::Creator::create() const;
