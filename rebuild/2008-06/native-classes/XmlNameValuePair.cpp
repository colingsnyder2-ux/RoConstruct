// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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

// 0057c3d0
bool XmlNameValuePair::getValue(RBX::ContentId& value) const
{
	if (valueType == CONTENTID) {
		value = *contentIdValue;
		return true;
	}

	if (valueType == STRING) {
		value = RBX::ContentId(*stringValue);
		clearValue();
		contentIdValue = new RBX::ContentId(value);
		valueType = CONTENTID;
		return true;
	}

	return false;
}

// 0057c550
bool XmlNameValuePair::getValue(unsigned& value) const
{
	if (valueType == UINT) {
		value = uintValue;
		return true;
	}

	if (valueType == STRING) {
		if (RBX::StringConverter<unsigned>::convertToValue(*stringValue, value)) {
			clearValue();
			uintValue = value;
			valueType = UINT;
			return true;
		}
	}

	return false;
}

// 0057c5b0
bool XmlNameValuePair::getValue(bool& value) const
{
	if (valueType == BOOL) {
		value = boolValue;
		return true;
	}

	if (valueType == STRING) {
		if (RBX::StringConverter<bool>::convertToValue(*stringValue, value)) {
			clearValue();
			boolValue = value;
			valueType = BOOL;
			return true;
		}
	}

	return false;
}

// 0057c610
bool XmlNameValuePair::getValue(float& value) const
{
	if (valueType == FLOAT) {
		value = floatValue;
		return true;
	}

	if (valueType == STRING) {
		if (RBX::StringConverter<float>::convertToValue(*stringValue, value)) {
			clearValue();
			floatValue = value;
			valueType = FLOAT;
			return true;
		}
	}

	return false;
}

// 0057c6e0
bool XmlNameValuePair::getValue(RBX::InstanceHandle& value) const
{
	if (valueType == NAME && *nameValue == value_IDREF_null) {
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}
	else if (valueType == STRING && value_IDREF_null == *stringValue) {
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}
	else if (valueType == STRING && *stringValue == "") {
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}

	if (valueType == HANDLE) {
		value = *handleValue;
		return true;
	}

	return false;
}
