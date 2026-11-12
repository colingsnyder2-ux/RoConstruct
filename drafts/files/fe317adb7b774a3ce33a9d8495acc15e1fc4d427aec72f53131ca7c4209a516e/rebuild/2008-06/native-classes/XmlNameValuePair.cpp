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

// Authentic donor reference: tools/rbxgs/Client/App/v8xml/XmlElement.cpp (constructor bodies follow the
// header's inline pattern). Every body below is verified by the compile/prove step, not by the donor alone.
#include "v8xml/XmlSerializer.h"
#include "util/Utilities.h"
#include "util/Debug.h"

XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, float value)
	: tag(tag), valueType(FLOAT), floatValue(value)
{
}

XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, bool value)
	: tag(tag), valueType(BOOL), boolValue(value)
{
}

XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, const unsigned value)
	: tag(tag), valueType(UINT), uintValue(value)
{
}

XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, RBX::ContentId value)
	: tag(tag), valueType(CONTENTID), contentIdValue(new RBX::ContentId(value))
{
}

bool XmlNameValuePair::getValue(RBX::ContentId& value) const
{
	if (valueType == CONTENTID)
	{
		value = *contentIdValue;
		return true;
	}
	else if (valueType == STRING)
	{
		value = RBX::ContentId(*stringValue);
		clearValue();
		contentIdValue = new RBX::ContentId(value);
		valueType = CONTENTID;
		return true;
	}

	return false;
}

bool XmlNameValuePair::getValue(int& value) const
{
	if (valueType == INT)
	{
		value = intValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<int>::convertToValue(*stringValue, value))
		{
			clearValue();
			intValue = value;
			valueType = INT;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(unsigned& value) const
{
	if (valueType == UINT)
	{
		value = uintValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<unsigned>::convertToValue(*stringValue, value))
		{
			clearValue();
			uintValue = value;
			valueType = UINT;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(bool& value) const
{
	if (valueType == BOOL)
	{
		value = boolValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<bool>::convertToValue(*stringValue, value))
		{
			clearValue();
			boolValue = value;
			valueType = BOOL;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(float& value) const
{
	if (valueType == FLOAT)
	{
		value = floatValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<float>::convertToValue(*stringValue, value))
		{
			clearValue();
			floatValue = value;
			valueType = FLOAT;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(RBX::InstanceHandle& value) const
{
	if (valueType == NAME && *nameValue == value_IDREF_null)
	{
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}
	else if (valueType == STRING && value_IDREF_null == *stringValue)
	{
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}
	else if (valueType == STRING && *stringValue == "")
	{
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}

	if (valueType == HANDLE)
	{
		value = *handleValue;
		return true;
	}

	return false;
}

template<>
bool XmlNameValuePair::isValueType<RBX::ContentId>() const
{
	return valueType == CONTENTID;
}

template<>
bool XmlNameValuePair::isValueType<std::string>() const
{
	return valueType == STRING;
}

std::string XmlNameValuePair::toString(XmlWriter* writer) const
{
	switch (valueType)
	{
	case NONE:
		return "";
	case BOOL:
		return RBX::StringConverter<bool>::convertToString(boolValue);
	case INT:
		return RBX::StringConverter<int>::convertToString(intValue);
	case UINT:
		return RBX::StringConverter<unsigned>::convertToString(uintValue);
	case FLOAT:
		return RBX::StringConverter<float>::convertToString(floatValue);
	case NAME:
		return nameValue->toString();
	case HANDLE:
		if (!handleValue->getTarget())
		{
			return value_IDREF_null.name;
		}
		else
		{
			int index = writer->getHandleIndex(*handleValue);

			char buffer[32];
			sprintf(buffer, "RBX%d", index);
			return buffer;
		}
	case STRING:
		return *stringValue;
	case CONTENTID:
		return contentIdValue->toString();
	default:
		RBXASSERT(0);
		return "";
	}
}

void XmlNameValuePair::replaceHandles(const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	typedef std::map<RBX::Instance*, RBX::InstanceHandle>::const_iterator Iter;

	if (valueType == HANDLE)
	{
		Iter r = isolationMap.find(handleValue->getTarget().get());

		if (r != isolationMap.end())
		{
			*handleValue = r->second;
		}
	}
}
