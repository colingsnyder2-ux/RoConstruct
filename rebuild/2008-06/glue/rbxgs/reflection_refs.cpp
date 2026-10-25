// Rebuild glue: the XML side of RefPropDescriptor (declared in the rbxgs-client overlay of
// reflection/reflection.h). A reference property is written as the target's handle and read back
// as an IDREF the binder resolves once every instance is loaded. Not byte-verified.
#include "reflection/reflection.h"
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"
#include "util/Handle.h"

namespace RBX
{
	void rebuildAnnounceIDREF(IReferenceBinder& binder, const XmlElement* element, Reflection::DescribedBase* owner, const IIDREF* idref)
	{
		binder.announceIDREF(element, owner, idref);
	}

	void rebuildWriteIDREF(XmlElement* element, Instance* target)
	{
		element->setValue(InstanceHandle(target));
	}
}
