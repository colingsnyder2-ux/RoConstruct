// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { class shared_count { public: void* pi_; ~shared_count(); }; }
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    template<class Y, class D> shared_ptr(Y* p, D d);
};
}
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual ~Object() {} };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
template<class T> class Creatable : public Object {
public:
    class Deleter { public: void operator()(T* instance) { T::predelete(instance); delete instance; } };
    template<class U> static boost::shared_ptr<U> create() { return boost::shared_ptr<U>(new U(), Deleter()); }
protected:
    Creatable() {}
    virtual ~Creatable() {}
};
class Instance : public GuidItemBase, public Creatable<Instance>, public DescribedBase, public Debugable {
public:
	static void predelete(Instance*);
	virtual ~Instance();
protected:
	Instance();
	char ipad[0x8c - 0x2c];
};
class NamedBase2009 : public Instance {
public:
	NamedBase2009(const char* name);
};
class Stats : public NamedBase2009 {
public:
	Stats() : NamedBase2009("Stats") {}
	virtual void s0();
};
template boost::shared_ptr<Stats> Creatable<Instance>::create<Stats>();
}
