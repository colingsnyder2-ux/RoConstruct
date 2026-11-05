// from server: 100% by EspClaude
// from server: 90% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_af0a42b4a535f5e2.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <exception>
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
template<class Base> class Creatable : public Object {
public:
	template<class T, class A0, class A1> static boost::shared_ptr<T> create(A0 a0, A1 a1);
};
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
template<int N> class Notifier {
public:
	Notifier();
	virtual ~Notifier();
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
                 public Notifier<0>,
                 public Notifier<1>,
                 public Notifier<2>,
                 public Notifier<3>,
                 public Notifier<4>,
                 public Notifier<5>
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
	void setParent(Instance* newParent);
};

enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
	static boost::shared_ptr<StandardOut> singleton();
	void print(MessageType type, const char* format, ...);
};
namespace Reflection {
template<class Signature> class TSignalDesc;
template<class A1> class TSignalDesc<void(A1)> {
public:
	void fire(SignalSource* source, A1 arg1);
};
template<class A1, class A2> class TSignalDesc<void(A1, A2)> {
public:
	void fire(SignalSource* source, A1 arg1, A2 arg2);
};
template<class A1, class A2, class A3> class TSignalDesc<void(A1, A2, A3)> {
public:
	void fire(SignalSource* source, A1 arg1, A2 arg2, A3 arg3);
};
}
}
struct SystemAddress {
	unsigned int binaryAddress;
	unsigned short port;
	const char* ToString(bool writePort = true) const;
	SystemAddress& operator=(const SystemAddress& input)
	{
		binaryAddress = input.binaryAddress;
		port = input.port;
		return *this;
	}
};
extern const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
struct Packet {
	int playerIndex;
	SystemAddress systemAddress;
	unsigned int length;
	unsigned int bitSize;
	unsigned char* data;
};
class RakPeerInterface;
enum PluginReceiveResult { RR_STOP_PROCESSING_AND_DEALLOCATE, RR_CONTINUE_PROCESSING, RR_STOP_PROCESSING };
enum {
	ID_CONNECTION_REQUEST_ACCEPTED = 13,
	ID_CONNECTION_ATTEMPT_FAILED = 14,
	ID_NO_FREE_INCOMING_CONNECTIONS = 17,
	ID_DISCONNECTION_NOTIFICATION = 18,
	ID_CONNECTION_LOST = 19,
	ID_CONNECTION_BANNED = 21,
	ID_INVALID_PASSWORD = 22
};
class PluginInterface {
public:
	virtual ~PluginInterface();
	virtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet);
};
namespace RBX {
namespace Network {
class Exposer {
public:
	static const char* IDTOString(unsigned char id);
};
class Replicator : public Instance { };
extern Reflection::TSignalDesc<void(std::string, boost::shared_ptr<Instance>)> event_ConnectionAccepted;
extern Reflection::TSignalDesc<void(std::string, int, std::string)> event_ConnectionFailed;
extern Reflection::TSignalDesc<void(std::string)> event_ConnectionRejected;
class Client : public Instance, public PluginInterface {
	char pad134[0xc];
	boost::shared_ptr<RakPeerInterface> rakPeer;
	SystemAddress serverId;
public:
	virtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet);
};
static __forceinline const SystemAddress* stash(const SystemAddress* volatile& slot, const SystemAddress* v)
{
	slot = v;
	return v;
}
PluginReceiveResult Client::OnReceive(RakPeerInterface* peer, Packet* packet)
{
	PluginReceiveResult result = PluginInterface::OnReceive(peer, packet);
	if (result != RR_CONTINUE_PROCESSING)
		return result;

	switch (packet->data[0])
	{
	case ID_CONNECTION_REQUEST_ACCEPTED:
		try
		{
			StandardOut::singleton()->print(MESSAGE_INFO, "Connection accepted from %s\n", packet->systemAddress.ToString());
			serverId = packet->systemAddress;

			boost::shared_ptr<Replicator> proxy = Creatable<Instance>::create<Replicator>(packet->systemAddress, this->rakPeer.get());
			proxy->setParent(this);

			event_ConnectionAccepted.fire(this, packet->systemAddress.ToString(), proxy);
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Client::OnReceive packet %d: %s", packet->data[0], e.what());
		}
		break;

	case ID_CONNECTION_ATTEMPT_FAILED:
	case ID_NO_FREE_INCOMING_CONNECTIONS:
	case ID_CONNECTION_BANNED:
		try
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to connect to %s. %s\n", packet->systemAddress.ToString(), Exposer::IDTOString(packet->data[0]));
			event_ConnectionFailed.fire(this, packet->systemAddress.ToString(), packet->data[0], Exposer::IDTOString(packet->data[0]));
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Client::OnReceive packet %d: %s", packet->data[0], e.what());
		}
		break;

	case ID_INVALID_PASSWORD:
		try
		{
			const SystemAddress* volatile paddress;
			StandardOut* so; (so = StandardOut::singleton().get(), so)->print(MESSAGE_ERROR, "Invalid version from %s", stash(paddress, &packet->systemAddress)->ToString());
			const SystemAddress& address = *paddress;
			event_ConnectionFailed.fire(this, address.ToString(), packet->data[0], Exposer::IDTOString(packet->data[0]));
			event_ConnectionRejected.fire(this, address.ToString());
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Client::OnReceive packet %d: %s", packet->data[0], e.what());
		}
		break;

	case ID_DISCONNECTION_NOTIFICATION:
	case ID_CONNECTION_LOST:
		serverId = UNASSIGNED_SYSTEM_ADDRESS;
		break;
	}

	return RR_CONTINUE_PROCESSING;
}
}
}

