// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}
struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
namespace RBX {
class Instance { public: virtual ~Instance(); };
template<class Base> class Creatable {
public:
    class Deleter { public: void operator()(Base* p); };
    template<class T, typename Arg0, typename Arg1> static boost::shared_ptr<T> create(Arg0 arg0, Arg1 arg1)
    {
        return boost::shared_ptr<T>(new T(arg0, arg1), Deleter());
    }
};
namespace Network {
class Server {
public:
    class ClientProxy : public Instance {
    public:
        ClientProxy(SystemAddress a, Server* s);
        char pad[0x2f40 - 4];
    };
};
}
template boost::shared_ptr<Network::Server::ClientProxy> Creatable<Instance>::create<Network::Server::ClientProxy, SystemAddress, Network::Server*>(SystemAddress, Network::Server*);
}
