// from server: 100% by EspClaude
// from server: 99% by EspClaude
// from server: 89% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a2b23449b8c17023.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <algorithm>
#include <boost/noncopyable.hpp>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
namespace RBX {
class Name;
class Instance;
struct DebugMember { DebugMember(); ~DebugMember(); int a, b; };
class __declspec(novtable) Debugable {
public:
	virtual void dump();
	bool validating;
	DebugMember member;
	Debugable() : validating(false) {}
};
class Object {
public:
	virtual ~Object() {}
};
template<class T> class Creatable : public Object { };
template<class T> class AbstractFactoryProduct : public Creatable<T> {
protected:
	AbstractFactoryProduct() {}
public:
	virtual const Name& getClassName() const = 0;
};
class SignalSource { public: virtual ~SignalSource(); int a, b; };
class DescribedBase1 { public: virtual ~DescribedBase1(); };
class Described : public SignalSource, public DescribedBase1 {
public:
	Described();
	virtual ~Described();
};
template<int N> class InstanceNotifier {
public:
	InstanceNotifier();
	virtual ~InstanceNotifier();
	char pad[0x1c];
};
template<class T> class Association {
	std::vector<boost::shared_ptr<T> > v;
};
extern long instanceCount;
class Instance : public boost::enable_shared_from_this<Instance>,
                 public Debugable,
                 public AbstractFactoryProduct<Instance>,
                 public Described,
                 public InstanceNotifier<0>,
                 public InstanceNotifier<1>,
                 public InstanceNotifier<2>,
                 public InstanceNotifier<3>,
                 public InstanceNotifier<4>,
                 public InstanceNotifier<5>
{
private:
	Association<Instance> assoc;
	Instance* parent;
	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > children;
	std::string name;
	bool archivable;
protected:
	Instance();
public:
	virtual ~Instance();
public:
	virtual const Name& getClassName() const;
};

template<class Class>
boost::shared_ptr<Class> shared_from(Class* r);
template<typename T>
class CopyOnWrite : public boost::noncopyable
{
private:
	boost::shared_ptr<T> object;
public:
	boost::shared_ptr<T>& write()
	{
		if (!object)
		{
			object = boost::shared_ptr<T>(new T());
			return object;
		}
		else if (object.use_count() <= 1)
		{
			return object;
		}
		else
		{
			object = boost::shared_ptr<T>(new T(*object));
			return object;
		}
	}
};
template<class Class, class Event> class Listener {
public:
	virtual void onEvent(const Class* source, const Event& event) {}
};
template<class Class, class Event> class Notifier {
public:
	Notifier();
	virtual ~Notifier();
	char pad[0x1c];
	void removeListener(Listener<Class, Event>* listener) const;
	template<typename T>
	static void disconnect(const T& notifier, Listener<Class, Event>* listener)
	{
		if (notifier)
			notifier->Notifier<Class, Event>::removeListener(listener);
	}
};
class ServiceProvider : public Instance {
public:
	static const ServiceProvider* findServiceProvider(const Instance* context);
};
template<class Class, class Base> class DescribedNonCreatable : public Base {
protected:
	DescribedNonCreatable();
};
namespace Reflection {
template<class Signature> class TSignalDesc {
public:
	void fire(SignalSource* source, const boost::shared_ptr<Instance> arg1);
};
}
namespace Network {
class CharacterAdded;
class ChatMessage;
class SuperSafeChanged;
class Player : public Instance, public Notifier<Player, CharacterAdded> {
public:
	virtual ~Player();
};
class Client {
public:
	static bool clientIsPresent(const Instance* context, bool testInDatamodel);
};
extern Reflection::TSignalDesc<void(boost::shared_ptr<Instance>)> event_PlayerRemoving;
class Players : public DescribedNonCreatable<Players, Instance>,
                public Notifier<Players, ChatMessage>,
                public Notifier<Players, SuperSafeChanged>,
                public Listener<Player, CharacterAdded>
{
	char pad174[0x198 - 0x174];
	CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > players;
public:
	static bool backendProcessing(const Instance* context, bool testInDatamodel);
protected:
	virtual void onChildRemoving(Instance* child);
};
inline bool Players::backendProcessing(const Instance* context, bool testInDatamodel)
{
	const ServiceProvider* sp = ServiceProvider::findServiceProvider(context);
	return sp && !Client::clientIsPresent(context, testInDatamodel);
}
void Players::onChildRemoving(Instance* child)
{
	Player* player = dynamic_cast<Player*>(child);
	if (!player)
		return;

	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myPlayers = players.write();
	myPlayers->erase(std::find(myPlayers->begin(), myPlayers->end(), shared_from(child)));

	if (backendProcessing(this, false))
		event_PlayerRemoving.fire(this, shared_from(player));

	Notifier<Player, CharacterAdded>::disconnect(player, this);
}
}
}
