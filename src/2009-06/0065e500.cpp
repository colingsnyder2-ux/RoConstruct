// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	virtual ~Instance();
	void setParent(Instance* p);
	char ipad[0x8c - 0x2c];
};
template<class B> class Creatable {
public:
    template<class T> static boost::shared_ptr<T> create();
};
class Notify2009 {
public:
	virtual void f0(); virtual void f1(); virtual void f2();
	virtual void f3(DescribedBase* d, const bool& b);
};
extern Notify2009* notify2009;
class Child : public Instance {};
class Holder : public Instance {
public:
    Child* findChild();
    bool hasChild() { bool r = findChild() != 0; return r; }
    void ensureChild();
};
void Holder::ensureChild()
{
    if (!hasChild())
    {
        boost::shared_ptr<Child> c = Creatable<Instance>::create<Child>();
        notify2009->f3(c.get(), false);
        c->setParent(this);
    }
}
}
