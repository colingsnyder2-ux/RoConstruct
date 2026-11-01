// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
class PropertyDescriptor { public: virtual ~PropertyDescriptor(); char pad[0x14]; };
template<class T> class TypedPropertyDescriptor : public PropertyDescriptor {
public:
	class __declspec(novtable) GetSet { public:
		virtual ~GetSet();
		virtual bool isReadOnly() const = 0;
		virtual T getValue(const DescribedBase* instance) const = 0; };
	T getValue(const DescribedBase* instance) const { return getset->getValue(instance); }
	GetSet* getset;
};
class Property { public: const PropertyDescriptor* descriptor; };
}
class Instance { public: char pad[0x18]; Reflection::DescribedBase db; operator const Reflection::DescribedBase*() const { return &db; } };
extern Reflection::TypedPropertyDescriptor<bool> prop_X;
class Node;
void setX(Node* n, bool v);
template<class F> struct Bind { F f; bool v; };
class Container { public: template<class F> void visit(F f); };
class Owner {
public:
	char pad[0xdc];
	Instance* part;
	char pad2[0xf4 - 0xe0];
	Container* target;
	void onPropertyChanged(Instance* src, const Reflection::Property& p);
};
void Owner::onPropertyChanged(Instance* src, const Reflection::Property& p) {
	if (src == part && p.descriptor == &prop_X) {
		bool v = part ? prop_X.getValue(&part->db) : false;
		Bind<void (*)(Node*, bool)> b = { &setX, v };
		if (target)
			target->visit(b);
	}
}
}
