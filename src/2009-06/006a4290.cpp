// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Name { public: std::string name; };
class XmlValue { public: bool getValue(const Name*& value) const; };
class XmlAttribute { char pad[8]; XmlValue value; public: bool getValue(const Name*& v) const { return value.getValue(v); } };
class XmlElement {
	char pad[0x10];
	const Name* tag;
public:
	const Name& getTag() const { return *tag; }
	const XmlAttribute* findAttribute(const Name& name) const;
};
class IReferenceBinder;
extern const Name& name_name;
class Instance {
public:
	virtual void readProperty(const XmlElement* propertyElement, IReferenceBinder& binder);
	void readProperties(const XmlElement* container, IReferenceBinder& binder);
};
class PVInstance : public Instance {
public:
	virtual void readProperty(const XmlElement* propertyElement, IReferenceBinder& binder);
};
void PVInstance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	if (propertyElement->getTag().name.compare("Feature") == 0) {
		const RBX::Name* name = NULL;
		const XmlAttribute* attribute = propertyElement->findAttribute(name_name);
		if (attribute != NULL) {
			attribute->getValue(name);
		}
		if (name->name.compare("Part") == 0) {
			readProperties(propertyElement, binder);
			return;
		}
		if (name->name.compare("Item") == 0) {
			readProperties(propertyElement, binder);
			return;
		}
	}
	Instance::readProperty(propertyElement, binder);
}
}
