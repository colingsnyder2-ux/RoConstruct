// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "v8xml/XmlSerializer.h"

bool XmlElement::isXsiNil() const
{
	const XmlAttribute* xsiNilAttribute = NULL;
	for (const XmlAttribute* attribute = attributes.firstChild(); attribute != NULL; attribute = attribute->nextSibling())
	{
		if (&attribute->getTag() == &name_xsinil)
		{
			xsiNilAttribute = attribute;
			break;
		}
	}

	bool isXsiNil;
	return xsiNilAttribute && xsiNilAttribute->getValue(isXsiNil) && isXsiNil;
}

int XmlWriter::getHandleIndex(RBX::InstanceHandle h)
{
	std::map<RBX::InstanceHandle, int>::iterator iter = handles.find(h);
	if (iter == handles.end())
	{
		int index = handles.size();
		handles[h] = index;
		return index;
	}

	return iter->second;
}
