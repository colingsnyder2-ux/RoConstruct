// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 2008-06 native TypedPropertyDescriptor<T> string/XML members of the ContentId-derived property types (inactive).
// reflection/property.h declares getStringValue / writeValue without a generic body; the bodies below are the
// per-type members the registry names (identity-closure), flags/includes copied from Inferred_00597bd0.cpp (the
// TextureId setStringValue sibling).
#include "util/TextureId.h"
#include "util/Sound.h"
#include "reflection/reflection.h"
#include "v8xml/XmlElement.h"
#include "util/Name.h"

namespace RBX {
namespace Reflection {

// 00597b50 ?getStringValue@?$TypedPropertyDescriptor@VTextureId@RBX@@@Reflection@RBX@@UBE?AV?$basic_string...
// getValue (out of line 0061a7b0, folded with the std::string instance) into a temporary, then
// StringConverter<TextureId>::convertToString (005b6940, folded with a string-copy helper), then ~TextureId.
template<>
std::string TypedPropertyDescriptor<TextureId>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<TextureId>::convertToString(getValue(instance));
}

// 00615640 ?writeValue@?$TypedPropertyDescriptor@VSoundId@Soundscape@RBX@@@Reflection@RBX@@EBEXPBVDescribedBase@23@PAVXmlElement@@@Z
// getValue (0061a7b0) into a temporary, a by-value ContentId copy of it (string copy + the +0x1c word) passed to
// XmlNameValuePair::setValue(ContentId) 0056c9e0 on the XmlElement base at +0x10, then the temporary's destructor.
template<>
void TypedPropertyDescriptor<Soundscape::SoundId>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

}
}
