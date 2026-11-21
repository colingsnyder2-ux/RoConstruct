// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00597f30: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/TextureId.h"
#include "reflection/reflection.h"
#include "util/Name.h"

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<TextureId>::setVariant(DescribedBase* instance, const Value& value) const
{
	getset->setValue(instance, value.get<TextureId>());
}

}
}
