// >>> native-status (generated) -- do not edit >>>
// XmlElement | 2008-06 | draft (no current byte proof)
// 0/10 mapped addresses byte-exact | 10 unproved | no mapped strings | by auto (+2) (mixed 2)
// <<< native-status | src 79714071 | roc native-status --write
#include "v8xml/XmlElement.h"

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
