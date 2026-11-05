// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Codegen analog of XmlAttribute::XmlAttribute<RBX::InstanceHandle>(const Name&, InstanceHandle).
// The target constructs XmlNameValuePair at +8 (lea ecx,[esi+8]) after zeroing
// Sibling::next at +0; the 4 bytes at +4 are not touched by this constructor.
// InstanceHandle is a boost::shared_ptr {px, pn}; pn has use count at +4,
// weak count at +8, dispose in vtable slot 1 and destroy in slot 2.
#include <intrin.h>

namespace boost { namespace detail {
class sp_counted_base {
	long use_count_;
	long weak_count_;
public:
	virtual ~sp_counted_base() {}
	virtual void dispose() = 0;
	virtual void destroy() { delete this; }
	void add_ref_copy() { _InterlockedIncrement(&use_count_); }
	void release()
	{
		if (_InterlockedDecrement(&use_count_) == 0)
		{
			dispose();
			weak_release();
		}
	}
	void weak_release()
	{
		if (_InterlockedDecrement(&weak_count_) == 0)
			destroy();
	}
};
} }

namespace RBX {
class Instance;
class Name;
class InstanceHandle {
	Instance* px;
	boost::detail::sp_counted_base* pn;
public:
	InstanceHandle(const InstanceHandle& other) : px(other.px), pn(other.pn)
	{
		if (pn != 0) pn->add_ref_copy();
	}
	~InstanceHandle() { if (pn != 0) pn->release(); }
};

template<class Class>
class Sibling {
	Class* next;
	int unused;
protected:
	Sibling() : next(0) {}
};
}

class XmlNameValuePair {
	const RBX::Name& tag;
	int valueType;
	void* value;
public:
	XmlNameValuePair(const RBX::Name& tag, RBX::InstanceHandle value);
};

class XmlAttribute : public RBX::Sibling<XmlAttribute>, public XmlNameValuePair {
public:
	template<typename T>
	XmlAttribute(const RBX::Name& tag, T value)
		: XmlNameValuePair(tag, value)
	{
	}
};

template XmlAttribute::XmlAttribute(const RBX::Name&, RBX::InstanceHandle);
