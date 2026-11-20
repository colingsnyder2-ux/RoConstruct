// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00597bd0 ?setStringValue@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@UBE_NPAVDescribedBase@23@AB...
// (registry identity-closure; flags/includes copied from Inferred_00597f30.cpp, the TextureId setVariant sibling).
// Body: default TextureId (basic_string ctor + Name::getNullName 00554270), StringConverter<TextureId>::convertToValue
// (00597480, COMDAT-folded with the SoundId converter), getset (+0x18) vtable slot 3 setValue, `ret 8`.
#include "util/TextureId.h"
#include "reflection/reflection.h"
#include "util/Name.h"

namespace RBX {
namespace Reflection {

// 00597bd0
template<>
bool TypedPropertyDescriptor<TextureId>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	TextureId value;
	if (StringConverter<TextureId>::convertToValue(text, value))
	{
		setValue(instance, value);
		return true;
	}
	return false;
}

}
}
