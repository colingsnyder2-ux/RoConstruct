// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "v8xml/XmlElement.h"

const RBX::Name& value_IDREF_null = RBX::Name::declare("null", 1);     // 007f37c0
const RBX::Name& value_IDREF_nil = RBX::Name::declare("nil", 2);       // 007f37e0
const RBX::Name& name_referent = RBX::Name::declare("referent", 7);    // 007f3880
const RBX::Name& name_name = RBX::Name::declare("name", 14);           // 007f3940
const RBX::Name& tag_xmlnsxsi = RBX::Name::declare("xmlns:xsi", 5);    // 007f3840
const RBX::Name& tag_roblox = RBX::Name::declare("roblox", 9);         // 007f38a0
const RBX::Name& tag_version = RBX::Name::declare("version", 10);      // 007f38c0
const RBX::Name& tag_External = RBX::Name::declare("External", 11);    // 007f38e0
const RBX::Name& tag_class = RBX::Name::declare("class", 38);          // 007f3b60
const RBX::Name& tag_Item = RBX::Name::declare("Item", 39);            // 007f3b80
const RBX::Name& tag_Properties = RBX::Name::declare("Properties", 40);// 007f3ba0
const RBX::Name& tag_xsinoNamespaceSchemaLocation = RBX::Name::declare("xsi:noNamespaceSchemaLocation", 49); // 007f3c40

bool XmlNameValuePair::isValueEqual(const RBX::Name* value) const
{
	switch (valueType) {
	case STRING: {
		const std::string& text = *stringValue;

		return value->name.compare(text) == 0;
	}
	case NAME:
		return value == nameValue;
	default:
		return false;
	}
}

bool XmlNameValuePair::getValue(std::string& value) const
{
	if (valueType == STRING) {
		value = *stringValue;
		return true;
	}

	return false;
}

bool XmlNameValuePair::getValue(const RBX::Name*& value) const
{
	if (valueType == NAME) {
		value = nameValue;
		return true;
	}

	if (valueType == STRING) {
		value = &RBX::Name::declare(stringValue->c_str(), -1);

		XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

		self->clearValue();

		self->nameValue = value;
		self->valueType = NAME;

		return true;
	}

	return false;
}

bool XmlNameValuePair::getValue(int& value) const
{
	if (valueType == INT) {
		value = intValue;
		return true;
	}

	if (valueType == STRING && RBX::StringConverter<int>::convertToValue(*stringValue, value)) {
		XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

		self->clearValue();

		self->intValue = value;
		self->valueType = INT;

		return true;
	}

	return false;
}

// 0057c670 (registry func_0057c670; after getValue(float&) 0057c610, caller 0056e760): the DOUBLE (9) read, the FLOAT
// (7) widening and the STRING parse (StringConverter<double>::convertToValue 005be680) share one clearValue 0057c2d0 /
// store-double tail (0057c6b7).
bool XmlNameValuePair::getValue(double& value) const
{
	if (valueType == DOUBLE) {
		value = doubleValue;
		return true;
	}

	if (valueType == FLOAT) {
		value = floatValue;
		clearValue();
		doubleValue = value;
		valueType = DOUBLE;
		return true;
	}

	if (valueType == STRING && RBX::StringConverter<double>::convertToValue(*stringValue, value)) {
		clearValue();
		doubleValue = value;
		valueType = DOUBLE;
		return true;
	}

	return false;
}

void XmlNameValuePair::clearValue() const
{
	switch (valueType) {
	case STRING:
		delete stringValue;
		break;
	case CONTENTID:
		delete contentIdValue;
		break;
	case HANDLE:
		delete handleValue;
		break;
	}

	valueType = NONE;
}

const XmlElement* XmlElement::findFirstChildByTag(const RBX::Name& _tag) const
{
	for (const XmlElement* child = firstChild(); child != NULL; child = child->nextSibling()) {
		if (&child->getTag() == &_tag) {
			return child;
		}
	}

	return NULL;
}

const XmlElement* XmlElement::findNextChildWithSameTag(const XmlElement* node) const
{
	for (const XmlElement* next = node->nextSibling(); next != NULL; next = next->nextSibling()) {
		if (&next->getTag() == &node->getTag()) {
			return next;
		}
	}

	return NULL;
}

const XmlAttribute* XmlElement::findAttribute(const RBX::Name& name) const
{
	for (const XmlAttribute* attribute = attributes.firstChild(); attribute != NULL;
		 attribute = attribute->nextSibling()) {
		if (&attribute->getTag() == &name) {
			return attribute;
		}
	}

	return NULL;
}

XmlAttribute* XmlElement::findAttribute(const RBX::Name& name)
{
	for (XmlAttribute* attribute = attributes.firstChild(); attribute != NULL; attribute = attribute->nextSibling()) {
		if (&attribute->getTag() == &name) {
			return attribute;
		}
	}

	return NULL;
}
