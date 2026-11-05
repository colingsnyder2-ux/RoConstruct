// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_c184b32a8810e0dc.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <list>
#include <boost/scoped_ptr.hpp>
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
class DescribedBase0 { public: virtual ~DescribedBase0(); int a, b; };
class DescribedBase1 { public: virtual ~DescribedBase1(); };
class Described : public DescribedBase0, public DescribedBase1 {
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
	virtual void setName(const std::string& value);
};

template<typename T>
class CopyOnWrite : public boost::noncopyable
{
private:
	boost::shared_ptr<T> object;
public:
	CopyOnWrite(const T& object)
		: object(new T(object))
	{
	}
};
template<class Class, class Event> class __declspec(novtable) Listener {
public:
	virtual void onEvent(const Class* source, Event event) = 0;
};
template<class Class, class Event> class Notifier {
public:
	Notifier();
	virtual ~Notifier();
	char pad[0x1c];
};
template<class Class, class Base> class DescribedNonCreatable : public Base {
protected:
	DescribedNonCreatable();
};
}
class PluginInterface {
public:
	PluginInterface();
	virtual ~PluginInterface();
};
class RakPeerInterface;
template<class Class>
class PluginInterfaceAdapter : public PluginInterface
{
private:
	Class* c;
protected:
	PluginInterfaceAdapter(Class* c)
		: PluginInterface(),
		  c(c)
	{
	}
};
namespace RBX {
namespace Network {
class Player;
class CharacterAdded {};
class ChatMessage { public: ChatMessage(const ChatMessage&); ~ChatMessage(); char pad[0x24]; };
class SuperSafeChanged {};
class AbuseReporter { public: ~AbuseReporter(); };
class Players : public DescribedNonCreatable<Players, Instance>,
                public Notifier<Players, ChatMessage>,
                public Notifier<Players, SuperSafeChanged>,
                public Listener<Player, CharacterAdded>
{
private:
	class Plugin;
	boost::scoped_ptr<AbuseReporter> abuseReporter;
	std::list<ChatMessage> chatHistory;
	boost::scoped_ptr<Plugin> plugin;
	CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > players;
	boost::shared_ptr<Player> localPlayer;
	RakPeerInterface* peer;
	int maxPlayers;
	virtual void onEvent(const Player* source, CharacterAdded event);
public:
	Players();
	virtual ~Players();
};
class Players::Plugin : public PluginInterfaceAdapter<Players>
{
public:
	Plugin(Players* players)
		: PluginInterfaceAdapter<Players>(players)
	{
	}
};
Players::Players()
	: players(std::vector<boost::shared_ptr<Instance> >()),
	  peer(NULL),
	  maxPlayers(12)
{
	setName("Players");
	plugin.reset(new Plugin(this));
}
}
}
