// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a9f31f8e657914eb.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/scoped_ptr.hpp>
#include <map>
#include <stddef.h>
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
	virtual ~Instance();
public:
	virtual const Name& getClassName() const;
	void setName(const std::string& value);
};
class Service {};
template<class Class, class Event> class Listener {
public:
	virtual void onEvent(const Class* source, const Event& event) {}
};
class RunService;
class Heartbeat;
class Players;
class worker_thread { public: ~worker_thread(); };
}
class RakPeerInterface {
public:
	virtual ~RakPeerInterface();
	virtual bool Startup();
	virtual void InitializeSecurity();
	virtual void DisableSecurity();
	virtual void SetMaximumIncomingConnections(unsigned short numberAllowed);
	virtual unsigned short GetMaximumIncomingConnections() const;
	virtual unsigned short NumberOfConnections() const;
	virtual void SetIncomingPassword(const char* passwordData, int passwordDataLength);
};
class PluginInterface {
public:
	virtual ~PluginInterface();
};
namespace RBX {
namespace API { extern std::string version; }
namespace Network {
class Peer : public Instance, public PluginInterface, public Listener<RunService, Heartbeat> {
	int pad138[2];
protected:
	boost::scoped_ptr<RakPeerInterface> rakPeer;
	Peer();
	virtual ~Peer();
};
struct PingWorker {
	int handle;
	int count;
	int pending;
	bool busy;
	char pad0d[3];
	bool stopped;
	PingWorker() : count(0), pending(0), busy(false), stopped(false) {}
	~PingWorker();
};
class Server : public Peer, public Service {
	int outgoingPort;
	boost::shared_ptr<Players> players;
	PingWorker pingWorker;
	std::map<int, std::string> clients;
public:
	Server();
	virtual ~Server();
	friend struct Check;
};
struct Check {
	typedef char c1[(offsetof(Server, players) == 0x148 && offsetof(Server, pingWorker) == 0x150) ? 1 : -1];
	typedef char c2[(offsetof(Server, clients) == 0x164) ? 1 : -1];
};
Server::Server()
	: outgoingPort(0)
{
	setName("NetworkServer");
	rakPeer->SetMaximumIncomingConnections(64);
	rakPeer->SetIncomingPassword(API::version.c_str(), (int)API::version.size());
}
}
}
