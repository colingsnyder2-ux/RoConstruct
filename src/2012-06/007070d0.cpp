// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll App/v8xml/SerializerV2.cpp

// Candidate translation unit (score above; library headers required).
#include "v8xml/SerializerV2.h"

#include "decomp.h"
#include "util/ContentProvider.h"
#include "util/Name.h"
#include "util/standardout.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#include "v8xml/XmlSerializer.h"

#include <G3D/Log.h>
#include <algorithm>
#include <cstring>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <stdexcept>
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
		const XmlNameValuePair* valueIDREF, RBX::Reflection::DescribedBase* propertyOwner, const RBX::IIDREF* idref
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
// FUNCTION: ROBLOX 0x005a2040
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
// FUNCTION: ROBLOX 0x005a22a0
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
// FUNCTION: ROBLOX 0x005a2360
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
// FUNCTION: ROBLOX 0x005a2420
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
// FUNCTION: ROBLOX 0x005a3270
bool ArchiveBinder::resolveRefs()
{
	size_t resolvedCount = std::count_if(
		idrefBindings.begin(), idrefBindings.end(), std::bind1st(std::mem_fun(&ArchiveBinder::resolveIDREF), this)
	);

	return MergeBinder::resolveRefs() && resolvedCount == idrefBindings.size();
}

// FUNCTION: WEBSERVICE 0x10097740
// FUNCTION: ROBLOX 0x005a32b0
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

// FUNCTION: ROBLOX 0x005a33f0
void SerializerV2::merge(const XmlElement* root, RBX::DataModel* dataModel)
{
	RBX::MergeBinder binder;

	const XmlElement* child = root->firstChild();
	while (child != NULL) {
		const XmlAttribute* referent = child->findAttribute(name_referent);
		RBX::InstanceHandle h;
		referent->getValue(h);
		boost::shared_ptr<RBX::Instance> instance = h.getTarget();

		if (child->getTag() != tag_External) {
			if (child->getTag() == name_DeleteItem) {
				instance->remove();
			}
			else if (instance) {
				instance->read(child, binder);
			}
			else {
				dataModel->getWorkspace()->readChild(child, binder);
			}
		}

		child = child->nextSibling();
	}

	binder.resolveRefs();
}

// FUNCTION: WEBSERVICE 0x10098450
// FUNCTION: ROBLOX 0x005a3ee0
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
// FUNCTION: ROBLOX 0x005a3f90
bool ArchiveBinder::processIDREF(
	const XmlNameValuePair* valueIDREF, RBX::Reflection::DescribedBase* propertyOwner, const RBX::IIDREF* idref
)
{
	if (!MergeBinder::processIDREF(valueIDREF, propertyOwner, idref)) {
		IDREFBinding binding = {valueIDREF, propertyOwner, idref};

		idrefBindings.push_back(binding);
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x10098620
// FUNCTION: ROBLOX 0x005a40b0
void SerializerV2::loadInstances(XmlElement* root, std::vector<boost::shared_ptr<RBX::Instance> >& instances)
{
	if (root->getTag() == tag_roblox) {
		const XmlAttribute* version = root->findAttribute(tag_version);
		if (version && version->getValue(schemaVersionLoading) && schemaVersionLoading >= 4) {
			ArchiveBinder binder;
			const XmlElement* itemElement = root->findFirstChildByTag(tag_Item);
			while (itemElement) {
				const RBX::Name* className = NULL;
				if (itemElement->findAttributeValue(tag_class, className)) {
					boost::shared_ptr<RBX::Instance> instance =
						RBX::AbstractFactoryProduct<RBX::Instance>::create(*className);
					if (instance) {
						instance->read(itemElement, binder);
						instances.push_back(instance);
					}
					else {
						RBX::StandardOut::singleton()->print(
							RBX::MESSAGE_WARNING,
							"Unknown object class \"%s\" while reading XML",
							className ? className->c_str() : ""
						);
					}
				}
				itemElement = root->findNextChildWithSameTag(itemElement);
			}

			binder.resolveRefs();
			return;
		}
	}

	G3D::Log::common()->println("Version 1.0 - 3.0 model files not supported - all future version will be supported");
}

// FUNCTION: WEBSERVICE 0x10098830
// FUNCTION: ROBLOX 0x005a42c0
void SerializerV2::isolateHandles(XmlElement* root)
{
	std::map<RBX::Instance*, RBX::InstanceHandle> isolationMap;

	buildIsolationMap(root, isolationMap);

	isolate(root, isolationMap);
}

// FUNCTION: WEBSERVICE 0x100988e0
// FUNCTION: ROBLOX 0x005a4370
void SerializerV2::load(XmlElement* root, RBX::DataModel* dataModel)
{
	ArchiveBinder binder;

	dataModel->readChildren(root, binder);

	binder.resolveRefs();
}

// FUNCTION: WEBSERVICE 0x10098970
// FUNCTION: ROBLOX 0x005a4400
void SerializerV2::loadXML(std::istream& stream, RBX::DataModel* dataModel)
{
	TextXmlParser machine(stream.rdbuf());
	std::auto_ptr<XmlElement> root = machine.parse();

	if (root->getTag() == tag_roblox) {
		const XmlAttribute* version = root->findAttribute(tag_version);

		if (!version->getValue(schemaVersionLoading)) {
			throw std::runtime_error("SerializerV2::loadXML no version number");
		}

		if (schemaVersionLoading < 4) {
			throw std::runtime_error("SerializerV2::loadXML schemaVersionLoading<4");
		}

		load(root.get(), dataModel);
	}
	else {
		schemaVersionLoading = 1;
		throw std::runtime_error("SerializerV2::loadXML ill-formed XML. No Roblox tag");
	}

	dataModel->setDirty(false);
}

// STUB: WEBSERVICE 0x10098b30
// STUB: ROBLOX 0x005a45c0
void SerializerV2::load(std::istream& stream, RBX::DataModel* dataModel)
{
	char header[5];
	header[4] = 0;
	if (!stream.read(header, 4).good()) {
		throw std::runtime_error("SerializerV2::load can't read header");
	}

	if (strcmp(header, "RBX_") != 0) {
		stream.clear();
		stream.seekg(0, std::ios_base::beg);
	}
	else {
		unsigned long fileFormatVersion;
		if (!stream.read((char*) &fileFormatVersion, 4).good()) {
			throw std::runtime_error("SerializerV2::load can't read old fileFormatVersion");
		}
		if (fileFormatVersion != 1) {
			throw std::runtime_error("SerializerV2::load canfileFormatVersion!=1");
		}

		unsigned long contentPos = 0;
		if (!stream.read((char*) &contentPos, 4).good()) {
			throw std::runtime_error("SerializerV2::load can't read contentPos");
		}

		if (contentPos != 0) {
			std::streamoff xmlPos = stream.tellg();
			stream.clear();
			stream.seekg(contentPos, std::ios_base::beg);

			while (stream.peek()) {
				char id[33];
				id[32] = 0;
				if (!stream.read(id, 32).good()) {
					throw std::runtime_error("SerializerV2::load error reading compound file (1)");
				}

				unsigned long contentLength;
				if (!stream.read((char*) &contentLength, 4).good()) {
					throw std::runtime_error("SerializerV2::load error reading compound file (2)");
				}

				char compression;
				if (!stream.read(&compression, 1).good()) {
					throw std::runtime_error("SerializerV2::load error reading compound file (3)");
				}
				if (compression != 0) {
					throw std::runtime_error("SerializerV2::load error reading compound file (4)");
				}

				RBX::ContentProvider::singleton().readContent(id, stream, contentLength);
			}

			stream.clear();
			stream.seekg(xmlPos, std::ios_base::beg);
		}

		char xmlCompression;
		if (!stream.read(&xmlCompression, 1).good()) {
			throw std::runtime_error("SerializerV2::load error reading compound file (5)");
		}
		if (xmlCompression != 0) {
			throw std::runtime_error("SerializerV2::load error reading compound file (6)");
		}
	}

	loadXML(stream, dataModel);
}
