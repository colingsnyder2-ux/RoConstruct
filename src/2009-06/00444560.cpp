// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std { template<class T> class auto_ptr { T* p; public: explicit auto_ptr(T* q) : p(q) {} auto_ptr(auto_ptr& o) : p(o.release()) {} ~auto_ptr() { delete p; } T* release() { T* t = p; p = 0; return t; } }; }
void __cdecl operator delete(void* p) throw();
namespace boost { struct once_flag { long v; }; void call_once(once_flag& flag, void (*f)()); }
namespace RBX { namespace Reflection {
class ClassDescriptor; class DescribedBase;
class Type { public: char tpad[4]; };
class EnumDescriptor : public Type {};
template<class Enum> class EnumDesc : public EnumDescriptor {
public:
	static boost::once_flag onceFlag;
	static void init();
	static const EnumDesc& get();
	static const EnumDesc& singleton() { boost::call_once(onceFlag, &init); return get(); }
};
class PropertyDescriptor {
public:
	enum Functionality { };
	PropertyDescriptor(ClassDescriptor& cd, const Type& type, const char* name, const char* category, Functionality f);
	virtual ~PropertyDescriptor();
	char pad[0x14];
};
class __declspec(novtable) EnumPropertyDescriptor : public PropertyDescriptor {
public:
	EnumPropertyDescriptor(ClassDescriptor& cd, const EnumDescriptor& ed, const char* name, const char* category, Functionality f)
		: PropertyDescriptor(cd, ed, name, category, f), enumDescriptor(ed) {}
	const EnumDescriptor& enumDescriptor;
};
template<class Class, class Enum> class EnumPropDescriptor : public EnumPropertyDescriptor {
public:
	class __declspec(novtable) GetSet { public:
		virtual bool isReadOnly() const = 0; };
	typedef Enum (Class::*Getter)() const;
	typedef void (Class::*Setter)(Enum);
	static std::auto_ptr<GetSet> makeGetSet(Getter g, Setter s, int x);
	EnumPropDescriptor(const char* name, const char* category, Getter g, Setter s, int x, Functionality f)
		: EnumPropertyDescriptor(Class::classDescriptor(), EnumDesc<Enum>::singleton(), name, category, f),
		  getset(makeGetSet(g, s, x).release()), enumDesc(EnumDesc<Enum>::singleton()) {}
	std::auto_ptr<GetSet> getset;
	const EnumDesc<Enum>& enumDesc;
};
}
class B0 { public: virtual void f0(); };
class B1 { public: virtual void f1(); };
class Target : public B0 { public: static Reflection::ClassDescriptor& classDescriptor(); };
enum TargetEnum { TE0 };
template class Reflection::EnumPropDescriptor<Target, TargetEnum>;
}
