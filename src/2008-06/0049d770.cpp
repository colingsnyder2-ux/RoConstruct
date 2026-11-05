// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net-dll roc_unit_59a74edd08c96c8d.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
// Players::OnReceive (2008-06 0049d770). Real RakNet 3.0 BitStream/RakPeerInterface,
// real std::string/std::list and boost smart pointers. RBX views: the Instance view is the
// proven 004b9bd0 hierarchy (parent 0x104, enable_shared_from_this base 0xe4, size 0x130);
// Players members at 0x174/0x178, ChatMessage (0x48) and AbuseReport (0x30) are read from
// the target (OnReceive frame, ctor 00496c20 / 00499320).
#include <stddef.h>
#include <string>
#include <vector>
#include <list>
#include <ostream>
#include <exception>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/thread/mutex.hpp>
#include <map>
#include <RakPeerInterface.h>
#include <BitStream.h>
#include <MessageIdentifiers.h>
// 2008 RakNet numbers user packets from 0x4c: target dispatches 0x51/0x52.
namespace RBX { namespace Network { enum { ID_CHAT_ALL = 0x51, ID_REPORT_ABUSE = 0x52 }; } }

namespace RBX {
class Name { public: static const Name& lookup(const std::string& sName); };
struct Instance;struct XmlElement;struct IReferenceBinder;struct ServiceProvider;
struct Guid:boost::noncopyable {struct Data {const Name*scope;int index;bool operator<(const Data&) const;};Data data;static const Name& getLocalScope();};
template<class T>struct GuidItem {virtual ~GuidItem();bool registeredGuid;Guid guid;static bool lookupByGuid(const Guid::Data&,T*&);};
struct Object {virtual ~Object();};template<class T>struct Creatable:Object{};
template<class T>struct AbstractFactoryProduct:Creatable<T> {virtual const Name&getClassName()const=0;};
namespace Reflection {
struct PropertyDescriptor;struct SignalSource {virtual ~SignalSource();void*signals;};
struct DescribedBase:SignalSource {void*descriptor;};
}
struct Debugable {virtual void dump(std::ostream&);};
struct RaiseRange;
template<class T,class Event>struct Listener;
template<class T,class Event>struct Notifier {
 virtual ~Notifier();std::vector<Listener<T,Event>*>listeners;RaiseRange*range;
 virtual void onAddListener(Listener<T,Event>*)const;virtual void onRemoveListener(Listener<T,Event>*)const;
};
struct ChildAdded;struct ChildRemoved;struct DescendentAdded;struct DescendentRemoving;struct PropertyChanged;struct AncestorChanged;
template<class T>struct Association {struct Item;std::vector<Item*>items;};
template<class T>struct CopyOnWrite:boost::noncopyable {boost::shared_ptr<T>object;};
struct Instance:GuidItem<Instance>,AbstractFactoryProduct<Instance>,Reflection::DescribedBase,Debugable,
 Notifier<Instance,ChildAdded>,Notifier<Instance,ChildRemoved>,Notifier<Instance,DescendentAdded>,Notifier<Instance,DescendentRemoving>,Notifier<Instance,AncestorChanged>,Notifier<Instance,PropertyChanged>,boost::enable_shared_from_this<Instance>,boost::noncopyable {
 virtual ~Instance();
 Association<Instance>assoc;Instance*parent;CopyOnWrite<std::vector<boost::shared_ptr<Instance> > >children;std::string name;bool archivable;
 Instance* getParent() const {return parent;}
};
template<typename To, typename From>
boost::shared_ptr<To> shared_from_dynamic_cast(boost::enable_shared_from_this<From>* r);

enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
	static boost::shared_ptr<StandardOut> singleton();
	void print(MessageType type, const char* format, ...);
};

struct GuidRegistry {std::map<Guid::Data,Instance*> tree;boost::mutex mutex;};
extern GuidRegistry* globalGuidRegistry;
extern int guidRegistryInitialized;
void initializeGuidRegistry();
void initializeGuidOnce(void (__cdecl*)(),int*);
template<> bool GuidItem<Instance>::lookupByGuid(const Guid::Data& key,Instance*& result) {
    const Name* scope=key.scope;
    if(&Guid::getLocalScope()==scope) {result=0;return true;}
    initializeGuidOnce(initializeGuidRegistry,&guidRegistryInitialized);
    GuidRegistry* map=globalGuidRegistry;
    boost::mutex::scoped_lock guard(map->mutex);
    std::map<Guid::Data,Instance*>::const_iterator it=map->tree.find(key);
    if(it!=map->tree.end()) {result=it->second;return true;}
    result=0;return false;
}

namespace Network {
RakNet::BitStream& operator>>(RakNet::BitStream& stream, int& value);
RakNet::BitStream& operator>>(RakNet::BitStream& stream, std::string& value);

class Player;
struct ChatMessage
{
	std::string guid;
	std::string message;
	boost::shared_ptr<Player> source;
	boost::shared_ptr<Player> destination;
	ChatMessage(const char* message, boost::shared_ptr<Player> source);
	~ChatMessage();
};

struct AbuseReport
{
	struct Message { int userID; std::string text; };
	int submitterID;
	int allegedAbuserID;
	std::string comment;
	std::list<Message> messages;
	AbuseReport();
	~AbuseReport();
};

class AbuseReporter
{
public:
	void add(AbuseReport& r, const std::list<ChatMessage>& chatHistory);
};

class Players : public Instance
{
private:
	char unused[0x174 - sizeof(Instance)];
	boost::scoped_ptr<AbuseReporter> abuseReporter;
	std::list<ChatMessage> chatHistory;
public:
	bool OnReceive(RakPeerInterface*, Packet*);
private:
	void addChatMessage(const ChatMessage& message);
};
typedef char assert_instance[sizeof(Instance)==0x130?1:-1];
typedef char assert_parent[offsetof(Instance,parent)==0x104?1:-1];

bool Players::OnReceive(RakPeerInterface* peer, Packet* packet)
{
	switch (packet->data[0])
	{
	case ID_CHAT_ALL:
		try
		{
			RakNet::BitStream bitStream(packet->data, packet->length, false);
			bitStream.IgnoreBits(8);

			std::string scopeName;
			bitStream >> scopeName;

			Guid::Data id;
			id.scope = &Name::lookup(scopeName);
			bitStream >> id.index;

			Instance* instance = NULL;
			GuidItem<Instance>::lookupByGuid(id, instance);

			std::string message;
			bitStream >> message;

			if (!instance)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, "Chat message from unknown Player %s %s", packet->systemAddress.ToString(), message.c_str());
			}
			else if (instance->getParent() == this)
			{
				ChatMessage event(message.c_str(), shared_from_dynamic_cast<Player>(instance));
				addChatMessage(event);
				peer->Send((const char*)packet->data, packet->length, HIGH_PRIORITY, RELIABLE, 2, packet->systemAddress, true);
			}
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Players::OnReceive packet %d: %s", packet->data[0], e.what());
		}
		return false;

	case ID_REPORT_ABUSE:
		try
		{
			if (abuseReporter)
			{
				RakNet::BitStream bitStream(packet->data, packet->length, false);
				bitStream.IgnoreBits(8);

				AbuseReport r;
				bitStream >> r.submitterID;
				bitStream >> r.allegedAbuserID;
				bitStream >> r.comment;

				abuseReporter->add(r, chatHistory);
			}
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Players::OnReceive packet %d: %s", packet->data[0], e.what());
		}
		return false;

	default:
		return true;
	}
}
}}
