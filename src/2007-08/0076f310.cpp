// from server: 100% by EspClaude
// from server: 83% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 roc_claude_c9584cc604927a78.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 0076f310 / 0076f440: dynamic initializers of reflected member-function descriptors
// for RBX::Network::Client::connect and RBX::Network::Server::start, each followed by
// atexit(destructor stub). Strings read from the exe: 0x79c4e0 "Connect", 0x79c4e8 "server",
// 0x79c4f0 "serverPort", 0x79c4fc "clientPort", 0x79c508 "threadSleepTime", 0x79cc24 "Start",
// 0x787068 "port". Trailing immediates 0x1e and 0 are pushed after the names. The member-function
// pointer is pushed as an 8-byte {fn, 0} pair (eax = fn, ecx = 0), i.e. a multiple-inheritance
// representation; the empty bases below only select that representation.
#include <string>

namespace RBX {
namespace Network {
struct PeerBase0 {};
struct PeerBase1 {};

class Client : public PeerBase0, public PeerBase1
{
public:
	void connect(std::string server, int serverPort, int clientPort, int threadSleepTime);
};

class Server : public PeerBase0, public PeerBase1
{
public:
	void start(int port, int threadSleepTime);
};
} // namespace Network

template <class Class>
class BoundFuncDesc4
{
public:
	typedef void (Class::*Func)(std::string, int, int, int);
	BoundFuncDesc4(Func func, const char* name, const char* arg1, const char* arg2, const char* arg3,
		const char* arg4, int default4, int security);
	~BoundFuncDesc4();
};

template <class Class>
class BoundFuncDesc2
{
public:
	typedef void (Class::*Func)(int, int);
	BoundFuncDesc2(Func func, const char* name, const char* arg1, const char* arg2, int default2, int security);
	~BoundFuncDesc2();
};
} // namespace RBX

using namespace RBX;

static BoundFuncDesc4<Network::Client> func_connect(&Network::Client::connect, "Connect", "server", "serverPort",
	"clientPort", "threadSleepTime", 30, 0);

static BoundFuncDesc2<Network::Server> func_start(&Network::Server::start, "Start", "port", "threadSleepTime", 30, 0);
