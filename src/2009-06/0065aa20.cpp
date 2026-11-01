// from server: 89% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class ClassDescriptor; }
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class DescribedBase { public: virtual void d0(); const Reflection::ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
};
template<class T> struct Counter { static int count; };
template<typename Class, typename DerivedClass, const char* const* ClassName>
class FactoryProduct : public DerivedClass {
public:
	static Reflection::ClassDescriptor& classDescriptor();
	FactoryProduct() : DerivedClass() { this->descriptor = &classDescriptor(); ++Counter<Class>::count; }
	virtual ~FactoryProduct() {}
};
class Camera;
extern const char* const sCamera;
template class FactoryProduct<Camera, Instance, &sCamera>;
}
