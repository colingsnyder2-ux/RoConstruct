// native-flags: 0049f500 size=135 unit=RBX::Network::Client
extern "C" void* (__cdecl *malloc)(unsigned int);
void __cdecl operator delete(void*);

namespace RBX {
class Script;
template<class T> class Creatable;
namespace Network {
class RakPeerInterface;
struct SystemAddress {
    unsigned int address;
    unsigned short port;
};
class Replicator {
    char storage[0x2d68];
public:
    Replicator(SystemAddress, RakPeerInterface*);
    static void* operator new(unsigned int size) { return malloc(size); }
    static void operator delete(void* p) { ::operator delete(p); }
};
}
}

namespace boost {
template<class T> class shared_ptr {
    T* pointer;
    void* count;
public:
    template<class Y, class D> shared_ptr(Y*, D);
};
}

// NEEDS-DECL: boost::shared_ptr<RBX::Script> sub_0049f500(RBX::Network::SystemAddress, RBX::Network::RakPeerInterface*)
boost::shared_ptr<RBX::Script> sub_0049f500(RBX::Network::SystemAddress addr, RBX::Network::RakPeerInterface* peer)
{
    int tag = 0;
    *reinterpret_cast<volatile char*>(&tag) = 0;
    return boost::shared_ptr<RBX::Script>(
        reinterpret_cast<RBX::Script*>(new RBX::Network::Replicator(addr, peer)), tag);
}
