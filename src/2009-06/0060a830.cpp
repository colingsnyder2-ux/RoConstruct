// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <stdio.h>
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    ~shared_ptr();
    bool operator!() const { return px == 0; }
};
}
namespace RBX {
class Instance;
class Name { public: std::string name; };
template<class T> class StringConverter { public: static std::string convertToString(const T& v); };
class InstanceHandle {
public:
    boost::shared_ptr<Instance> target;
    InstanceHandle(const InstanceHandle& o);
    boost::shared_ptr<Instance> getTarget() const;
};
class ContentId { public: std::string id; const std::string& toString() const { return id; } };
}
class XmlWriter { public: int getHandleIndex(RBX::InstanceHandle h); };
extern const RBX::Name& value_IDREF_null;
class XmlNameValuePair {
public:
    enum ValueType { NONE, NAME, STRING, CONTENTID, BOOL, INT, UINT, FLOAT, HANDLE, DOUBLE };
    int pad;
    ValueType valueType;
    union {
        bool boolValue;
        int intValue;
        unsigned int uintValue;
        float floatValue;
        double doubleValue;
        const RBX::Name* nameValue;
        RBX::InstanceHandle* handleValue;
        std::string* stringValue;
        RBX::ContentId* contentIdValue;
    };
    std::string toString(XmlWriter* writer) const;
};
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
