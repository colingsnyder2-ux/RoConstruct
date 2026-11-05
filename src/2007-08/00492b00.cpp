// from server: 100% by EspClaude
// roc 2007-08 00492b00  unit: RBX::Network::Players  size: 189 bytes
// AbuseReporter appendMessage (2008-06 0049bf90 family), 2007 XML layout: 4-byte value union,
// XmlElement 0x20, XmlAttribute 0x10 (sizes from the target's operator new arguments).
// roc-flags: /O2 /GS /EHsc /MD
#include <string>
namespace RBX {
struct Name {static const Name&declare(const char*,int=-1);};
template<class T>struct Sibling {T*next;Sibling():next(0){}void setNextSibling(T*n){next=n;}};
template<class T>struct Parent {
 T*first;T*last;Parent():first(0),last(0){}
 void pushBackChild(T*child){if(!last)first=child;else last->setNextSibling(child);last=child;}
};
}
struct XmlNameValuePair {
 enum ValueType{NONE,NAME,STRING,CONTENTID,BOOL,INT,UINT,FLOAT,HANDLE};
 const RBX::Name&tag;mutable ValueType valueType;
 union {std::string*stringValue;const RBX::Name*nameValue;void*handleValue;bool boolValue;int intValue;unsigned uintValue;float floatValue;};
 XmlNameValuePair(const RBX::Name&t):tag(t),valueType(NONE){}
 XmlNameValuePair(const RBX::Name&t,int v):tag(t),valueType(INT),intValue(v){}
 ~XmlNameValuePair(){clearValue();}
 void clearValue()const;
 void setValue(std::string);
};
struct XmlAttribute:RBX::Sibling<XmlAttribute>,XmlNameValuePair {XmlAttribute(const RBX::Name&t,int v):XmlNameValuePair(t,v){}};
struct XmlElement:RBX::Sibling<XmlElement>,RBX::Parent<XmlElement>,XmlNameValuePair {
 RBX::Parent<XmlAttribute>attributes;
 explicit XmlElement(const RBX::Name&t):XmlNameValuePair(t){}
 ~XmlElement();
 void addAttribute(const RBX::Name&t,int v){attributes.pushBackChild(new XmlAttribute(t,v));}
 XmlElement*addChild(XmlElement*e){pushBackChild(e);return e;}
};
typedef char element_size[sizeof(XmlElement)==0x20?1:-1];
typedef char attribute_size[sizeof(XmlAttribute)==0x10?1:-1];
namespace RBX {namespace Network {
struct AbuseReport {
 struct Message {int userID;std::string text;};
};
void __cdecl appendMessage(const AbuseReport::Message&m,XmlElement*parent){
 const RBX::Name&messageTag=RBX::Name::declare("message");
 XmlElement*e=parent->addChild(new XmlElement(messageTag));
 e->setValue(m.text);
 int userID=m.userID;
 const RBX::Name&userTag=RBX::Name::declare("userID");
 e->addAttribute(userTag,userID);
}
}}
