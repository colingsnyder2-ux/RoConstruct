// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/reflection/property.h"

namespace RBX {
namespace Reflection {
void RefPropertyDescriptor::setVariant(RBX::Reflection::DescribedBase* instance, const RBX::Reflection::Value& value) const
{
	boost::shared_ptr<RBX::Reflection::DescribedBase> ref = value.get<boost::shared_ptr<RBX::Reflection::DescribedBase> >();
	setRefValue(instance, ref.get());
}
}
}
