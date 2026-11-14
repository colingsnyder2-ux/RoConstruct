// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native XML reference binders (inactive).
// RBX::MergeBinder::announceIDREF 00443eb0 and processIDREF 00444a70 are already defined inline in
// native-headers/v8datamodel/MergeBinder2008.h (and metadata-load/v8xml/SerializerV2.h); they are not repeated here.
// ArchiveBinder::processIDREF 00593170 is declared out of line in SerializerV2.h and defined nowhere else.
#include "metadata-load/v8xml/SerializerV2.h"

// 00593170 ?processIDREF@ArchiveBinder@@UAE_NPBVXmlNameValuePair@@PAVDescribedBase@Reflection@RBX@@PBVIIDREF@5@@Z
// Calls MergeBinder::processIDREF 00444a70 directly; on failure pushes the binding onto idrefBindings (list at +0x3c:
// _Buynode 00595140, _Incsize 00595190) and always returns true.
bool ArchiveBinder::processIDREF(const XmlNameValuePair* valueIDREF, RBX::Reflection::DescribedBase* propertyOwner, const RBX::IIDREF* idref)
{
	if (!MergeBinder::processIDREF(valueIDREF, propertyOwner, idref))
	{
		IDREFBinding binding = {valueIDREF, propertyOwner, idref};
		idrefBindings.push_back(binding);
	}

	return true;
}
