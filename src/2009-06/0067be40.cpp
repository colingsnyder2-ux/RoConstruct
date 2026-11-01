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
template<const char* const* N> struct Counter { static int count; };
template<typename DerivedClass, const char* const* ClassName>
class NonFactoryProduct : public DerivedClass {
public:
	static Reflection::ClassDescriptor& classDescriptor();
	NonFactoryProduct() : DerivedClass() { this->descriptor = &classDescriptor(); ++Counter<ClassName>::count; }
};
extern const char* const sJointInstance;
template class NonFactoryProduct<Instance, &sJointInstance>;
}
