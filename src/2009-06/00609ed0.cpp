// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Instance;
class Name {
public:
	std::string name;
	bool operator==(const Name& other) const { return this == &other; }
	friend bool operator==(const Name& a, const std::string& b) { return a.name.compare(b) == 0; }
};
struct HandleRef {
	void* p;
	HandleRef& operator=(const HandleRef& other);
};
class InstanceHandle {
public:
	Instance* target;
	HandleRef ref;
	InstanceHandle(Instance* instance);
};
}
extern const RBX::Name& value_IDREF_null;
class XmlNameValuePair {
public:
	enum ValueType { NONE, NAME, STRING, A, B, C, D, E, HANDLE };
	virtual ~XmlNameValuePair();
	bool getValue(RBX::InstanceHandle& value) const;
	void clearValue() const;
	mutable ValueType valueType;
	union {
		mutable const RBX::Name* nameValue;
		mutable std::string* stringValue;
		mutable RBX::InstanceHandle* handleValue;
	};
};

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
