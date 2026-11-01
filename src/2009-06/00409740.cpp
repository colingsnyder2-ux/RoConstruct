// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std { template<class T> class auto_ptr { T* p; public: auto_ptr(auto_ptr& o) : p(o.release()) {} ~auto_ptr() { delete p; } T* release() { T* t = p; p = 0; return t; } }; }
void __cdecl operator delete(void* p) throw();
namespace RBX { namespace Reflection {
class ClassDescriptor; class DescribedBase;
template<class T> struct ExeCounter { static int count; };
class Type { public: template<class T> static const Type& singleton(); };
class PropertyDescriptor {
public:
	enum Functionality { };
	PropertyDescriptor(ClassDescriptor& cd, const Type& type, const char* name, const char* category, Functionality f);
	virtual ~PropertyDescriptor();
	char pad[0x14];
};
template<class T> inline const Type& typeOf() { ++ExeCounter<T>::count; return Type::singleton<T>(); }
template<class T> class TypedPropertyDescriptor : public PropertyDescriptor {
public:
	class __declspec(novtable) GetSet { public:
		virtual bool isReadOnly() const = 0;
		virtual T getValue(const DescribedBase* instance) const = 0;
		virtual void setValue(DescribedBase* instance, const T& value) const = 0; };
protected:
	TypedPropertyDescriptor(ClassDescriptor& cd, const char* name, const char* category, std::auto_ptr<GetSet> getset, Functionality f)
		: PropertyDescriptor(cd, typeOf<T>(), name, category, f), getset(getset) {}
	std::auto_ptr<GetSet> getset;
};
template class TypedPropertyDescriptor<bool>;
}}
