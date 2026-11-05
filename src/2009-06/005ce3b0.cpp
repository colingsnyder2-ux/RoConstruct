// from server: 100% by EspClaude
// from server: 99% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_3ab6267120072594.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include "util/Handle.h"
namespace RBX { class Name; }
class XmlNameValuePair
{
public:
	XmlNameValuePair(const RBX::Name& tag, RBX::InstanceHandle value);
	int pad[6];
};
template<class C> class ExeSibling { public: C* next; int exePad; ExeSibling() : next(0) {} };
class XmlAttribute : public ExeSibling<XmlAttribute>, public XmlNameValuePair
{
public:
	template<typename T>
	XmlAttribute(const RBX::Name& tag, T value)
		: XmlNameValuePair(tag, value)
	{
	}
};
template XmlAttribute::XmlAttribute(const RBX::Name&, RBX::InstanceHandle);
