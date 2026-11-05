// from server: 100% by king_originala
// from server: 76% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <stdexcept>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
};

class Logger {
public:
    void log(int level, const char* fmt, ...);
};
shared_ptr<Logger> __cdecl getLogger();

struct SocketDescriptor {
    SocketDescriptor(unsigned short port, const char* hostAddress);
    unsigned short port;
    char hostAddress[32];
};

class RakPeerInterface {
public:
    virtual ~RakPeerInterface();
    virtual bool Startup(unsigned short maxConnections, int threadSleepTimer, SocketDescriptor* socketDescriptors, unsigned socketDescriptorCount);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual bool Connect(const char* host, unsigned short remotePort, const char* passwordData, int passwordDataLength, unsigned connectionSocketIndex);
};

namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR, MESSAGE_SEVERE };
class StandardOut {
public:
    static StandardOut* singleton();
    void print(MessageType type, const char* message);
};

namespace API {
extern std::string version;
}

namespace Network {
class Client {
public:
    char pad[0x140];
    RakPeerInterface* rakPeer;
    void updateNetworkSimulator();
    void connect(std::string server, int serverPort, int clientPort, int threadSleepTime);
};

void Client::connect(std::string server, int serverPort, int clientPort, int threadSleepTime)
{
    if (server != "localhost" && server.find_first_of("192.168", 0, 7) != 0)
        StandardOut::singleton()->print(MESSAGE_SEVERE, " connect to an extranet game");

    SocketDescriptor d(clientPort, "");
    if (!rakPeer->Startup(1, threadSleepTime, &d, 1))
        throw std::runtime_error("Failed to start network client");

    RakPeerInterface* peer=rakPeer;
    if (!peer->Connect(server.c_str(), serverPort, API::version.c_str(), (int)API::version.size(), 0))
        throw std::runtime_error("Failed to connect to server");

    getLogger()->log(1, "Connecting to %s:%d", server.c_str(), serverPort);

    updateNetworkSimulator();
}
}
}
