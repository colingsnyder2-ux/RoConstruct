// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// >>> native-status (generated) -- do not edit >>>
// XmlNameValuePair | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 0abe95fa | roc native-status --write
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

// 0057c3d0 ?getValue@XmlNameValuePair@@QBE_NAAVContentId@RBX@@@Z
// STRING path: temporary ContentId(const std::string&) 00615440, assign, clearValue 0057c2d0, new ContentId copy (0x20).
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

// getValue(int&) 0057c4f0 is defined in XmlElement.cpp; not repeated here.

// 0057c550 ?getValue@XmlNameValuePair@@QBE_NAAI@Z  (StringConverter<unsigned>::convertToValue 005be610)
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

// 0057c5b0 ?getValue@XmlNameValuePair@@QBE_NAA_N@Z  (StringConverter<bool>::convertToValue 005bde60)
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

// 0057c610 ?getValue@XmlNameValuePair@@QBE_NAAM@Z  (StringConverter<float>::convertToValue 005be790)
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

// 0057c6e0 ?getValue@XmlNameValuePair@@QBE_NAAVInstanceHandle@RBX@@@Z
// Three separate new InstanceHandle(NULL) sites (EH states 0/1/2): NAME == value_IDREF_null (pointer compare),
// STRING equal to value_IDREF_null's text (string::compare), STRING == "" (operator==(string, const char*)).
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
