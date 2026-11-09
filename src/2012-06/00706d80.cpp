// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8xml/SerializerV2.cpp

// Candidate translation unit (score above; library headers required).
#include "v8xml/SerializerV2.h"

#include "decomp.h"
#include "util/Name.h"
#include "v8xml/XmlElement.h"

#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <string>

// SIZE 0x2c
class ArchiveBinder : public RBX::MergeBinder
{
public:
	// SIZE 0x0c
	struct IDREFBinding
	{
		const XmlNameValuePair* valueIDREF;            // 0x00
		RBX::Reflection::DescribedBase* propertyOwner; // 0x04
		const RBX::IIDREF* idref;                      // 0x08
	};

	virtual bool processID(const XmlNameValuePair* valueID, RBX::Instance* source);

	virtual bool processIDREF(
		const XmlNameValuePair* valueIDREF,
		RBX::Reflection::DescribedBase* propertyOwner,
		const RBX::IIDREF* idref
	);

	bool resolveIDREF(IDREFBinding binding);

	virtual bool resolveRefs();

private:
	std::map<std::string, RBX::InstanceHandle> idMap; // 0x14
	std::list<IDREFBinding> idrefBindings;            // 0x20
};

DECOMP_SIZE_ASSERT(ArchiveBinder, 0x2c)
DECOMP_SIZE_ASSERT(ArchiveBinder::IDREFBinding, 0x0c)

// FUNCTION: WEBSERVICE 0x100963c0
XmlElement* SerializerV2::newRootElement()
{
	static const RBX::Name& tag_xmlnsxmime = RBX::Name::declare("xmlns:xmime", -1);

	XmlElement* root = new XmlElement(tag_roblox);

	root->addAttribute(tag_xmlnsxmime, "http://www.w3.org/2005/05/xmlmime");
	root->addAttribute(tag_xmlnsxsi, "http://www.w3.org/2001/XMLSchema-instance");
	root->addAttribute(tag_xsinoNamespaceSchemaLocation, "http://www.roblox.com/roblox.xsd");
	root->addAttribute(tag_version, 4);

	root->addChild(new XmlElement(tag_External, &value_IDREF_null));
	root->addChild(new XmlElement(tag_External, &value_IDREF_nil));

	return root;
}

// FUNCTION: WEBSERVICE 0x10096560
void XmlNameValuePair::replaceHandles(const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	if (valueType == HANDLE) {
		std::map<RBX::Instance*, RBX::InstanceHandle>::const_iterator found =
			isolationMap.find(handleValue->getTarget().get());

		if (found != isolationMap.end()) {
			*handleValue = found->second;
		}
	}
}

// FUNCTION: WEBSERVICE 0x10096620
static void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	element->replaceHandles(isolationMap);

	for (XmlAttribute* attribute = element->getFirstAttribute(); attribute != NULL;
		 attribute = element->getNextAttribute(attribute)) {
		attribute->replaceHandles(isolationMap);
	}

	for (XmlElement* child = element->firstChild(); child != NULL; child = child->nextSibling()) {
		isolate(child, isolationMap);
	}
}

// FUNCTION: WEBSERVICE 0x10096730
bool ArchiveBinder::resolveIDREF(IDREFBinding binding)
{
	std::string s;
	binding.valueIDREF->getValue(s);

	std::map<std::string, RBX::InstanceHandle>::iterator iter = idMap.find(s);

	if (iter != idMap.end()) {
		const RBX::InstanceHandle& value = iter->second;

		binding.idref->assignIDREF(binding.propertyOwner, value);

		return true;
	}

	binding.idref->assignIDREF(binding.propertyOwner, RBX::InstanceHandle(NULL));

	return false;
}

// FUNCTION: WEBSERVICE 0x10096ff0
bool ArchiveBinder::resolveRefs()
{
	size_t resolvedCount = std::count_if(
		idrefBindings.begin(),
		idrefBindings.end(),
		std::bind1st(std::mem_fun(&ArchiveBinder::resolveIDREF), this)
	);

	return MergeBinder::resolveRefs() && resolvedCount == idrefBindings.size();
}

// FUNCTION: WEBSERVICE 0x10097740
static void buildIsolationMap(XmlElement* element, std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	const XmlAttribute* referent = element->findAttribute(name_referent);

	if (referent != NULL) {
		RBX::InstanceHandle h;

		referent->getValue(h);

		isolationMap[h.getTarget().get()] = RBX::InstanceHandle();
	}

	for (XmlElement* child = element->firstChild(); child != NULL; child = child->nextSibling()) {
		buildIsolationMap(child, isolationMap);
	}
}

// FUNCTION: WEBSERVICE 0x10098450
bool ArchiveBinder::processID(const XmlNameValuePair* valueID, RBX::Instance* source)
{
	if (!MergeBinder::processID(valueID, source)) {
		std::string s;
		valueID->getValue(s);

		idMap[s].linkTo(RBX::shared_from(source));
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x10098500
bool ArchiveBinder::processIDREF(
	const XmlNameValuePair* valueIDREF,
	RBX::Reflection::DescribedBase* propertyOwner,
	const RBX::IIDREF* idref
)
{
	if (!MergeBinder::processIDREF(valueIDREF, propertyOwner, idref)) {
		IDREFBinding binding = {valueIDREF, propertyOwner, idref};

		idrefBindings.push_back(binding);
	}

	return true;
}

// STUB: WEBSERVICE 0x10098830
void SerializerV2::isolateHandles(XmlElement* root)
{
	std::map<RBX::Instance*, RBX::InstanceHandle> isolationMap;

	buildIsolationMap(root, isolationMap);

	isolate(root, isolationMap);
}

// STUB: WEBSERVICE 0x100988e0
void SerializerV2::load(XmlElement* root, RBX::DataModel* dataModel)
{
	STUB(0x100988e0);

	ArchiveBinder binder;

	binder.resolveRefs();
}
