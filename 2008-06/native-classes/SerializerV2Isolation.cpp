// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// SerializerV2 handle isolation (v8xml/SerializerV2.cpp): buildIsolationMap 00592780 and
// SerializerV2::isolateHandles 00593480. Both lie in the ArchiveBinder / SerializerV2 object (between
// ArchiveBinder::resolveRefs 00592720 and ArchiveBinder() 00592940; loadInstances 00593250 and load 00593730 follow
// in SerializerV2Load.cpp, flags copied from it and ArchiveBinder.cpp). Identities: registry
// ?buildIsolationMap@@YAXPAVXmlElement@@AAV?$map@PAVInstance@RBX@@VInstanceHandle@2@...@std@@@Z (external linkage,
// self-recursive call at 00592892) and ?isolateHandles@SerializerV2@@SAXPAVXmlElement@@@Z. Body shape: donor
// rbxgs v8xml/SerializerV2.cpp. isolate 00591d30 is in the XmlElement object (next to
// XmlNameValuePair::replaceHandles 00591c60), so it is only declared here.
#include "../native-headers/v8xml/XmlElement.h"
#include "metadata-load/v8xml/SerializerV2.h"

void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap); // 00591d30

// 00592780. Callees: XmlElement::findAttribute(name_referent) 0057c2b0, XmlNameValuePair::getValue(InstanceHandle&)
// 0057c6e0, InstanceHandle::getTarget 004915b0, map<Instance*,InstanceHandle>::operator[] 00592610 (COMDAT twin),
// shared_ptr count assignment 004025b0. The RBXASSERTs compile out in release.
// BLOCKER (core util/Handle.h, header owner): it declares `~InstanceHandle(void);` out of line (INFERRED header-gap
// row), while the client inlines the shared_ptr release of h and drops the dtor of the null temporary. With that one
// line removed in a scratch copy of util/Handle.h this body is EXACT (measured batch 32).
void buildIsolationMap(XmlElement* element, std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	XmlAttribute* referent = element->findAttribute(name_referent);
	if (referent)
	{
		RBX::InstanceHandle h;
		referent->getValue(h);

		isolationMap[h.getTarget().get()] = RBX::InstanceHandle();
	}

	for (XmlElement* child = element->firstChild(); child != NULL; child = element->nextChild(child))
	{
		buildIsolationMap(child, isolationMap);
	}
}

// 00593480. Callees: map ctor 00589190, buildIsolationMap 00592780, isolate 00591d30, ~_Tree 004b16a0.
void SerializerV2::isolateHandles(XmlElement* root)
{
	std::map<RBX::Instance*, RBX::InstanceHandle> isolationMap;

	buildIsolationMap(root, isolationMap);
	isolate(root, isolationMap);
}
