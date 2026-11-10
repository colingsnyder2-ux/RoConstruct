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
