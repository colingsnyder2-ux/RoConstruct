// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <list>
namespace boost { template<class T> class shared_ptr { T* px; void* pn; }; template<class Sig> class signal; }
namespace RBX {
class Instance;
class Name { public: static const Name& declare(const char* name); };
namespace Reflection {
class ClassDescriptor;
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
template<class T> inline const Type& countedType() { ++ExeCounter<T>::n; return Type::singleton<T>(); }
class ValueHolder { public: virtual ~ValueHolder(); };
class Value {
public:
	Value();
	~Value() { delete holder; }
	const Type* type;
	ValueHolder* holder;
};
class SignatureDescriptor {
public:
	struct Item {
		const Name* name;
		const Type* type;
		const Value defaultValue;
	};
	typedef std::list<Item> Arguments;
	template<class T> __forceinline void addArgument(const char* name)
	{
		Item i = {&Name::declare(name), &countedType<T>(), Value()};
		arguments.push_back(i);
	}
	const Type* resultType;
	Arguments arguments;
};
class EventDescriptor {
public:
	EventDescriptor(ClassDescriptor& classDescriptor, const char* name);
	virtual ~EventDescriptor();
	char pad[0xc];
	SignatureDescriptor signature;
};
template<class Class, class Signature, class Sig> class EventDescBase : public EventDescriptor {
public:
	Sig Class::*sig;
	EventDescBase(Sig Class::*sig, const char* name)
		: EventDescriptor(Class::classDescriptor(), name), sig(sig) {}
};
template<int N, class Class, class Signature, class Sig> class EventDescImpl;
template<class Class, class Sig> class EventDescImpl<1, Class, void(boost::shared_ptr<Instance>), Sig>
	: public EventDescBase<Class, void(boost::shared_ptr<Instance>), Sig> {
public:
	EventDescImpl(Sig Class::*sig, const char* name, const char* arg1Name)
		: EventDescBase<Class, void(boost::shared_ptr<Instance>), Sig>(sig, name)
	{
		this->signature.template addArgument<boost::shared_ptr<Instance> >(arg1Name);
	}
};
template<class Class, class Signature, class Sig> class EventDesc : public EventDescImpl<1, Class, Signature, Sig> {
public:
	EventDesc(Sig Class::*sig, const char* name, const char* arg1Name)
		: EventDescImpl<1, Class, Signature, Sig>(sig, name, arg1Name) {}
};
}
namespace Network {
class Player { public: static Reflection::ClassDescriptor& classDescriptor(); };
}
template class Reflection::EventDesc<Network::Player, void(boost::shared_ptr<Instance>), boost::signal<void(boost::shared_ptr<Instance>)> >;
}
