// from server: 100% by colin
// from server: 97% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
#pragma pointers_to_members(full_generality, multiple_inheritance)

struct RefCount {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Ref {
    RefCount* count;
    void assign(const Ref&);
};

struct Endpoint {
    void setOwner(void*);
};

struct Shared {
    Endpoint* pointer;
    Ref reference;
    ~Shared();
    Shared& operator=(const Shared&);
    void clear();
};

inline Shared::~Shared()
{
    if (reference.count) {
        RefCount* p = reference.count;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

inline Shared& Shared::operator=(const Shared& other)
{
    pointer = other.pointer;
    reference.assign(other.reference);
    return *this;
}

struct Transport {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void stop(int, int);
    virtual bool active();
};

struct Server;

struct Binding {
    void (Server::*method)();
    Server* object;
    int unused;
    Binding(void (Server::* const&)(), Server*);
};

inline Binding::Binding(void (Server::* const& m)(), Server* s)
    : method(m), object(s)
{
}

struct Function {
    unsigned char storage[40];
    Function(const Binding&);
    ~Function();
};

struct Connection {
    unsigned char storage[16];
    ~Connection();
};

struct ConnectionHolder {
    unsigned char storage[16];
    void clear();
    void assign(const Connection&);
};

struct Peer {
    unsigned char prefix[20];
    unsigned char signal;
    void* getEndpoint();
    void registerCallback(Binding);
};

struct Manager {
    Connection connect(void*, const Function&, int);
};

extern Manager manager;
Shared __cdecl makeShared(void*);

struct Server {
    unsigned char prefix[320];
    Transport* transport;
    unsigned long reserved;
    Shared endpoint;
    ConnectionHolder connection;

    void change(Peer*, Peer*);
    void baseChange(Peer*, Peer*);
    void detach();
    void* owner();
    void callback();
};

void Server::change(Peer* oldPeer, Peer* newPeer)
{
    if (oldPeer) {
        endpoint.pointer->setOwner(0);
        if (transport->active())
            transport->stop(1000, 0);
        detach();
        endpoint.clear();
        connection.clear();
    }

    baseChange(oldPeer, newPeer);

    if (newPeer) {
        endpoint = makeShared(newPeer->getEndpoint());

        Endpoint* current = endpoint.pointer;
        current->setOwner(owner());

        newPeer->registerCallback(Binding(&Server::callback, this));

        Function function(Binding(&Server::callback, this));
        void* signal = &newPeer->signal;
        connection.assign(
            manager.connect(signal, function, 10));
    }
}
