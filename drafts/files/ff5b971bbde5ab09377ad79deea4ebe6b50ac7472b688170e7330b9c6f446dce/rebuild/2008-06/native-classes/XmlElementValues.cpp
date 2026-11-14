// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native XmlElement / XmlWriter leaves (inactive).
// XmlNameValuePair::setValue(InstanceHandle) 004915e0, setValue(ContentId) 0056c9e0 and XmlElement::addChild(const Name&)
// 00496bc0 are already defined inline in native-headers/v8xml/XmlElement.h; they are not repeated here.
#include "v8xml/XmlSerializer.h"

// 0057c810 ?isXsiNil@XmlElement@@QBE_NXZ
// The attribute walk (first attribute at +0x20, tag reference at +8, sibling link at +0) is findAttribute(name_xsinil)
// inlined; findAttribute is out of line in XmlElement.cpp, so this unit spells the same loop. getValue(bool&) 0057c5b0.
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

// 0057cf50 ?getHandleIndex@XmlWriter@@QAEHVInstanceHandle@RBX@@@Z
// handles.find 0057c8b0; on a miss the new index is handles.size() (+0x20) stored through operator[] 0057ce40.
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
