// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <exception>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long use;
    volatile long weak;
    void release()
    {
        if (_InterlockedDecrement(&use) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};

template <class T>
struct Shared {
    T* px;
    Control* pn;
    Shared(const Shared& other) : px(other.px), pn(other.pn)
    {
        if (pn)
            _InterlockedIncrement(&pn->use);
    }
    ~Shared()
    {
        if (pn)
            pn->release();
    }
    T* operator->() const { return px; }
};

struct StandardOut {
    static Shared<StandardOut> singleton();
    void __cdecl print(int type, const char* format, ...);
};

struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
    char* ToString(bool writePort) const;
};

struct Packet {
    unsigned short systemIndex;
    SystemAddress systemAddress;
    unsigned int length;
    unsigned int bitSize;
    unsigned char* data;
};

struct RakPeerInterface;

struct PluginInterface {
    virtual ~PluginInterface();
    virtual int OnReceive(RakPeerInterface* peer, Packet* packet);
};

struct Full;
struct Base2 { virtual ~Base2(); char storage[0x118]; };

struct Peer {
    static Shared<Peer> create(SystemAddress address, Full* owner);
    void attach(Full* owner);
    void start();
};

struct Registry {
    void add(Base2* owner, std::string address, Shared<Peer> peer);
};
extern Registry g_registry;


struct Head { virtual ~Head(); char storage[0x10]; };
struct Full : Head, Base2, PluginInterface {
    virtual int OnReceive(RakPeerInterface* peer, Packet* packet);
};

int Full::OnReceive(RakPeerInterface* rakPeer, Packet* packet)
{
    int result = PluginInterface::OnReceive(rakPeer, packet);
    if (result != 1)
        return result;
    if (packet->data[0] == 0x10) {
        try {
            StandardOut::singleton()->print(1, "New connection from %s\n", packet->systemAddress.ToString(true));
            Shared<Peer> peer = Peer::create(packet->systemAddress, this);
            peer->attach(this);
            peer->start();
            g_registry.add(this, std::string(packet->systemAddress.ToString(true)), peer);
        } catch (std::exception& e) {
            StandardOut::singleton()->print(3, "Server::OnReceive packet %d: %s", packet->data[0], e.what());
        }
    }
    return 1;
}
