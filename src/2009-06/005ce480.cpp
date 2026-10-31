// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } T* operator->() const { return px; } T& operator*() const { return *px; } typedef T* shared_ptr::*ub; operator ub() const { return px ? &shared_ptr::px : 0; } };
}
class XmlElement {
public:
	XmlElement* nextSibling;
	XmlElement* firstChild;
	XmlElement* lastChild;
	void pushBackChild(XmlElement* e) {
		if (lastChild == 0) firstChild = e; else lastChild->nextSibling = e;
		lastChild = e;
	}
};
namespace RBX {
class Instance {
public:
	virtual ~Instance();
	virtual void v1(); virtual void v2(); virtual void v3();
	virtual XmlElement* write();
	char pad[0x48];
	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > children;
	void writeChildren(XmlElement* container);
};
void Instance::writeChildren(XmlElement* container)
{
	if (children)
	{
		const std::vector<boost::shared_ptr<Instance> >& c = *children;
		for (std::vector<boost::shared_ptr<Instance> >::const_iterator it = c.begin(); it != c.end(); it++)
		{
			XmlElement* element = (*it)->write();
			if (element)
				container->pushBackChild(element);
		}
	}
}
}
