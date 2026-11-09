// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_837df9e66657a287.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Name.h"
#include <string>

template<typename Class> class Parent;

template<typename Class>
class Sibling
{
    template<typename C> friend class Parent;
private:
    Class* next;
protected:
    Sibling() : next(NULL) {}
public:
    Class* nextSibling() { return next; }
private:
    void setNextSibling(Class* sibling) { next = sibling; }
};

template<typename Class>
class Parent
{
private:
    Class* first;
    Class* last;
public:
    Parent() : first(NULL), last(NULL) {}
    void pushBackChild(Class* child)
    {
        if (!last)
            first = child;
        else
            last->setNextSibling(child);
        last = child;
    }
};

class XmlNameValuePair
{
public:
    enum ValueType { NONE = 0, NAME = 1, STRING = 2, CONTENTID = 3, BOOL = 4, INT = 5, UINT = 6, FLOAT = 7, HANDLE = 8 };
private:
    const RBX::Name& tag;
    mutable ValueType valueType;
    union
    {
        std::string* stringValue;
        mutable int intValue;
        mutable double doubleValue;
    };
    void clearValue() const;
public:
    XmlNameValuePair(const RBX::Name& tag, const int value) : tag(tag), valueType(INT), intValue(value) {}
    XmlNameValuePair(const RBX::Name& tag, const std::string& text) : tag(tag), valueType(STRING), stringValue(new std::string(text)) {}
    XmlNameValuePair(const RBX::Name& tag) : tag(tag), valueType(NONE) {}
    ~XmlNameValuePair() { clearValue(); }
    void setValue(std::string value);
};

class XmlAttribute : public Sibling<XmlAttribute>, public XmlNameValuePair
{
public:
    template<typename T>
    XmlAttribute(const RBX::Name& tag, T value) : XmlNameValuePair(tag, value) {}
};

class XmlElement : public Sibling<XmlElement>, public Parent<XmlElement>, public XmlNameValuePair
{
private:
    Parent<XmlAttribute> attributes;
public:
    XmlElement(const RBX::Name& tag) : XmlNameValuePair(tag) {}
protected:
    void addAttribute(XmlAttribute* attribute) { attributes.pushBackChild(attribute); }
public:
    template<typename T>
    void addAttribute(const RBX::Name& _tag, T value) { addAttribute(new XmlAttribute(_tag, value)); }
    XmlElement* addChild(const RBX::Name& _tag) { return addChild(new XmlElement(_tag)); }
    XmlElement* addChild(XmlElement* element) { pushBackChild(element); return element; }
};

namespace RBX {
namespace Network {
struct Message
{
    int userID;
    std::string text;
    std::string guid;
};

void writeMessage(const Message& m, XmlElement* parent)
{
    XmlElement* e = parent->addChild(RBX::Name::declare("message", -1));
    e->setValue(m.text);
    e->addAttribute(RBX::Name::declare("userID", -1), m.userID);
    e->addAttribute(RBX::Name::declare("guid", -1), m.guid);
}
}
}
