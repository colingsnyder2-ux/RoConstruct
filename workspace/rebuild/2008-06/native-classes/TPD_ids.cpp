// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// TypedPropertyDescriptor<TextureId/ContentId> getVariant / setVariant (00597c90, 00586330, 005864d0)
#include "util/TextureId.h"
#include "util/ContentProvider.h"
#include "reflection/reflection.h"
#include "util/Name.h"

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<TextureId>::getVariant(const DescribedBase* instance, Value& value) const
{
	value = getset->getValue(instance);
}

template<>
void TypedPropertyDescriptor<ContentId>::getVariant(const DescribedBase* instance, Value& value) const
{
	value = getset->getValue(instance);
}

template<>
void TypedPropertyDescriptor<ContentId>::setVariant(DescribedBase* instance, const Value& value) const
{
	getset->setValue(instance, value.get<ContentId>());
}

}
}
