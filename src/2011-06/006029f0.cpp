// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8xml/XmlElement.cpp

// Candidate translation unit (score above; library headers required).
#include "v8xml/XmlElement.h"

#include "util/ContentProvider.h"
#include "util/Handle.h"
#include "util/Name.h"
#include "util/Utilities.h"
#include "v8xml/XmlSerializer.h"

#include <cstdio>

const RBX::Name& value_IDREF_null = RBX::Name::declare("null", 1);
const RBX::Name& value_IDREF_nil = RBX::Name::declare("nil", 2);
const RBX::Name& name_xsinil = RBX::Name::declare("xsi:nil", 3);
const RBX::Name& name_xsitype = RBX::Name::declare("xsi:type", 4);
const RBX::Name& tag_xmlnsxsi = RBX::Name::declare("xmlns:xsi", 5);
const RBX::Name& name_root = RBX::Name::declare("root", 6);
const RBX::Name& name_referent = RBX::Name::declare("referent", 7);
const RBX::Name& name_DeleteItem = RBX::Name::declare("DeleteItem", 8);
const RBX::Name& tag_roblox = RBX::Name::declare("roblox", 9);
const RBX::Name& tag_version = RBX::Name::declare("version", 10);
const RBX::Name& tag_External = RBX::Name::declare("External", 11);
const RBX::Name& name_Ref = RBX::Name::declare("Ref", 12);
const RBX::Name& name_token = RBX::Name::declare("token", 13);
const RBX::Name& name_name = RBX::Name::declare("name", 14);
const RBX::Name& tag_Refs = RBX::Name::declare("Refs", 21);
const RBX::Name& tag_X = RBX::Name::declare("X", 23);
const RBX::Name& tag_Y = RBX::Name::declare("Y", 24);
const RBX::Name& tag_Z = RBX::Name::declare("Z", 25);
const RBX::Name& tag_R00 = RBX::Name::declare("R00", 26);
const RBX::Name& tag_R01 = RBX::Name::declare("R01", 27);
const RBX::Name& tag_R02 = RBX::Name::declare("R02", 28);
const RBX::Name& tag_R10 = RBX::Name::declare("R10", 29);
const RBX::Name& tag_R11 = RBX::Name::declare("R11", 30);
const RBX::Name& tag_R12 = RBX::Name::declare("R12", 31);
const RBX::Name& tag_R20 = RBX::Name::declare("R20", 32);
const RBX::Name& tag_R21 = RBX::Name::declare("R21", 33);
const RBX::Name& tag_R22 = RBX::Name::declare("R22", 34);
const RBX::Name& tag_R = RBX::Name::declare("R", 35);
const RBX::Name& tag_G = RBX::Name::declare("G", 36);
const RBX::Name& tag_B = RBX::Name::declare("B", 37);
const RBX::Name& tag_class = RBX::Name::declare("class", 38);
const RBX::Name& tag_Item = RBX::Name::declare("Item", 39);
const RBX::Name& tag_Properties = RBX::Name::declare("Properties", 40);
const RBX::Name& tag_Feature = RBX::Name::declare("Feature", 41);
const RBX::Name& tag_hash = RBX::Name::declare("hash", 45);
const RBX::Name& tag_null = RBX::Name::lookup("null");
const RBX::Name& tag_mimeType = RBX::Name::declare("mimeType", 48);
const RBX::Name& tag_xsinoNamespaceSchemaLocation = RBX::Name::declare("xsi:noNamespaceSchemaLocation", 49);

// FUNCTION: WEBSERVICE 0x10084ac0
XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, const char* text) : tag(tag), valueType(STRING)
{
	stringValue = new std::string(text);
}

// FUNCTION: WEBSERVICE 0x1008efe0
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

// FUNCTION: WEBSERVICE 0x1008f020
template <>
bool XmlNameValuePair::isValueType<RBX::ContentId>() const
{
	return valueType == CONTENTID;
}

// FUNCTION: WEBSERVICE 0x1008f030
template <>
bool XmlNameValuePair::isValueType<std::string>() const
{
	return valueType == STRING;
}

// FUNCTION: WEBSERVICE 0x1008f040
bool XmlNameValuePair::getValue(std::string& value) const
{
	if (valueType == STRING) {
		value = *stringValue;
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1008f060
const XmlElement* XmlElement::findFirstChildByTag(const RBX::Name& _tag) const
{
	for (const XmlElement* child = firstChild(); child != NULL; child = child->nextSibling()) {
		if (&child->getTag() == &_tag) {
			return child;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x1008f080
const XmlElement* XmlElement::findNextChildWithSameTag(const XmlElement* node) const
{
	for (const XmlElement* next = node->nextSibling(); next != NULL; next = next->nextSibling()) {
		if (&next->getTag() == &node->getTag()) {
			return next;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x1008f0e0
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

// FUNCTION: WEBSERVICE 0x1008f100
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

// FUNCTION: WEBSERVICE 0x1008f190
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

// FUNCTION: WEBSERVICE 0x1008f200
bool XmlNameValuePair::getValue(RBX::ContentId& value) const
{
	if (valueType == CONTENTID) {
		value = *contentIdValue;
		return true;
	}

	if (valueType == STRING) {
		value = RBX::ContentId(*stringValue);

		XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

		self->clearValue();

		self->contentIdValue = new RBX::ContentId(value);
		self->valueType = CONTENTID;

		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1008f320
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

// FUNCTION: WEBSERVICE 0x1008f380
bool XmlNameValuePair::getValue(unsigned int& value) const
{
	if (valueType == UINT) {
		value = uintValue;
		return true;
	}

	if (valueType == STRING && RBX::StringConverter<unsigned int>::convertToValue(*stringValue, value)) {
		XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

		self->clearValue();

		self->uintValue = value;
		self->valueType = UINT;

		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1008f3e0
bool XmlNameValuePair::getValue(bool& value) const
{
	if (valueType == BOOL) {
		value = boolValue;
		return true;
	}

	if (valueType == STRING && RBX::StringConverter<bool>::convertToValue(*stringValue, value)) {
		XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

		self->clearValue();

		self->boolValue = value;
		self->valueType = BOOL;

		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1008f440
bool XmlNameValuePair::getValue(float& value) const
{
	if (valueType == FLOAT) {
		value = floatValue;
		return true;
	}

	if (valueType == STRING && RBX::StringConverter<float>::convertToValue(*stringValue, value)) {
		XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

		self->clearValue();

		self->floatValue = value;
		self->valueType = FLOAT;

		return true;
	}

	return false;
}

// STUB: WEBSERVICE 0x1008f4a0
bool XmlNameValuePair::getValue(double& value) const
{
	if (valueType == DOUBLE) {
		value = doubleValue;
		return true;
	}

	if (valueType == FLOAT) {
		value = floatValue;
	}
	else if (valueType != STRING || !RBX::StringConverter<double>::convertToValue(*stringValue, value)) {
		return false;
	}

	XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

	self->clearValue();

	self->doubleValue = value;
	self->valueType = DOUBLE;

	return true;
}

// STUB: WEBSERVICE 0x1008f510
bool XmlNameValuePair::getValue(RBX::InstanceHandle& value) const
{
	XmlNameValuePair* self = const_cast<XmlNameValuePair*>(this);

	if (valueType == NAME && nameValue == &value_IDREF_null) {
		self->clearValue();

		self->handleValue = new RBX::InstanceHandle(NULL);
		self->valueType = HANDLE;
	}
	else if (valueType == STRING && value_IDREF_null.name.compare(*stringValue) == 0) {
		self->clearValue();

		self->handleValue = new RBX::InstanceHandle(NULL);
		self->valueType = HANDLE;
	}
	else if (valueType == STRING && *stringValue == "") {
		self->clearValue();

		self->handleValue = new RBX::InstanceHandle(NULL);
		self->valueType = HANDLE;
	}

	if (valueType == HANDLE) {
		value = *handleValue;
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1008f640
bool XmlElement::isXsiNil() const
{
	const XmlAttribute* attribute = findAttribute(name_xsinil);

	bool isNil;

	return attribute != NULL && attribute->getValue(isNil) && isNil;
}

// STUB: WEBSERVICE 0x1008fe70
std::string XmlNameValuePair::toString(XmlWriter* writer) const
{
	switch (valueType) {

	case BOOL:
		return RBX::StringConverter<bool>::convertToString(boolValue);

	case INT:
		return RBX::StringConverter<int>::convertToString(intValue);

	case UINT:
		return RBX::StringConverter<unsigned int>::convertToString(uintValue);

	case FLOAT:
		return RBX::StringConverter<float>::convertToString(floatValue);

	case DOUBLE:
		return RBX::StringConverter<double>::convertToString(doubleValue);

	case NAME:
		return nameValue->name;

	case HANDLE:
		if (!handleValue->getTarget()) {
			return value_IDREF_null.name;
		}
		else {
			char buffer[32];

			sprintf(buffer, "RBX%d", writer->getHandleIndex(*handleValue));

			return buffer;
		}

	case STRING:
		return *stringValue;

	case CONTENTID:
		return contentIdValue->toString();

	case NONE:
		return "";

	default:
		return "";
	}
}
