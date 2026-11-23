// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 2008-06 native TypedPropertyDescriptor<T>::writeValue for ContentId, MeshId and TextureId (00615640, identical-code
// folded across the content-id types; SoundId's is in TypedPropertyContentIdLeftovers.cpp). Flags and includes copied
// from that sibling unit: with /fp:fast the out-of-line getValue call is inlined away and the body is 37 bytes instead of 124.
#include "util/TextureId.h"
#include "util/MeshId.h"
#include "reflection/reflection.h"
#include "v8xml/XmlElement.h"
#include "util/Name.h"

namespace RBX {
namespace Reflection {

// 00615640 (vtable 008312e0 slot 10)
template<>
void TypedPropertyDescriptor<ContentId>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	// The explicit ContentId(...) keeps the by-value copy the exe makes (passing getValue()'s prvalue directly elides it).
	element->setValue(ContentId(getValue(instance)));
}

// 00615640 (vtable 00833318 slot 10)
template<>
void TypedPropertyDescriptor<MeshId>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// 00615640 (vtable 00832494 slot 10)
template<>
void TypedPropertyDescriptor<TextureId>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

}
}
