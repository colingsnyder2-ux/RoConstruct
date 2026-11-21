// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// isolate 00591d30 (?isolate@@YAXPAVXmlElement@@ABV?$map@PAVInstance@RBX@@VInstanceHandle@2@...@std@@@Z, registry
// name, external linkage). It lies in the XmlElement object directly after XmlNameValuePair::replaceHandles 00591c60
// (XmlNameValuePair.cpp, flags copied from it); its only caller is SerializerV2::isolateHandles 00593480
// (SerializerV2Isolation.cpp). Body shape from the target: replaceHandles on the element's own XmlNameValuePair
// (+0x10), then on every attribute (attributes list +0x20, XmlAttribute pair at +8, next sibling +0), then recursion
// over the child elements (Parent<XmlElement> first child +4, next sibling +0).
#include "../native-headers/v8xml/XmlElement.h"

void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap);

// 00591d30
void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	element->replaceHandles(isolationMap);

	for (XmlAttribute* attribute = element->getFirstAttribute(); attribute != NULL; attribute = element->getNextAttribute(attribute))
	{
		attribute->replaceHandles(isolationMap);
	}

	for (XmlElement* child = element->firstChild(); child != NULL; child = element->nextChild(child))
	{
		isolate(child, isolationMap);
	}
}
