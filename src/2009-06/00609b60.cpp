// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Name {
public:
	static const Name& declare(const char* sName);
};
}
class XmlNameValuePair {
public:
	enum ValueType { NONE, NAME, STRING };
	virtual ~XmlNameValuePair();
	bool getValue(const RBX::Name*& value) const;
	void clearValue() const;
	mutable ValueType valueType;
	union {
		mutable const RBX::Name* nameValue;
		mutable std::string* stringValue;
	};
};

bool XmlNameValuePair::getValue(const RBX::Name*& value) const
{
	if (valueType == NAME)
	{
		value = nameValue;
		return true;
	}
	else if (valueType == STRING)
	{
		value = &RBX::Name::declare(stringValue->c_str());
		clearValue();
		nameValue = value;
		valueType = NAME;
		return true;
	}
	return false;
}
