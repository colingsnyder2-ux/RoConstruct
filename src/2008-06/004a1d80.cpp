// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_serverlogexpression_f4031b747f0f3f6e.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
typedef std::string String;
struct SocketDescriptor {
    unsigned short port;
    char host[32];
    SocketDescriptor(unsigned short, const char*);
};

struct Address {
    unsigned long host;
    unsigned short port;
    const char* toString(bool) const;
};

struct Peer {
    virtual void reserved0() = 0;
    virtual bool start(unsigned short, unsigned int, SocketDescriptor*, unsigned int) = 0;
    virtual void reserved2() = 0;
    virtual void reserved3() = 0;
    virtual void reserved4() = 0;
    virtual void reserved5() = 0;
    virtual void reserved6() = 0;
    virtual void reserved7() = 0;
    virtual void reserved8() = 0;
    virtual void reserved9() = 0;
    virtual void reserved10() = 0;
    virtual void reserved11() = 0;
    virtual void reserved12() = 0;
    virtual void reserved13() = 0;
    virtual void reserved14() = 0;
    virtual void reserved15() = 0;
    virtual void reserved16() = 0;
    virtual void reserved17() = 0;
    virtual void reserved18() = 0;
    virtual void reserved19() = 0;
    virtual void reserved20() = 0;
    virtual void reserved21() = 0;
    virtual void reserved22() = 0;
    virtual void reserved23() = 0;
    virtual void reserved24() = 0;
    virtual void reserved25() = 0;
    virtual void reserved26() = 0;
    virtual void reserved27() = 0;
    virtual void reserved28() = 0;
    virtual void reserved29() = 0;
    virtual void reserved30() = 0;
    virtual void reserved31() = 0;
    virtual void reserved32() = 0;
    virtual void reserved33() = 0;
    virtual void reserved34() = 0;
    virtual void reserved35() = 0;
    virtual void reserved36() = 0;
    virtual void reserved37() = 0;
    virtual void reserved38() = 0;
    virtual void reserved39() = 0;
    virtual Address getAddress(Address) = 0;
};

typedef boost::shared_ptr<void> Shared;

struct Failure {
    char storage[40];
    Failure(const String&);
};

extern Address defaultAddress;
extern unsigned char failureType;
extern "C" __declspec(noreturn) void __stdcall throwFailure(void*, void*);
extern Shared __cdecl getLogger();
extern void __cdecl logMessage(void*, int, const char*, ...);

struct Server {
    char padding[0x140];
    Peer* peer;
    unsigned int port;
    void start(unsigned short, unsigned int);
    void update();
};

__forceinline void report(const Shared& logger, const Address& address) {
    void* object=logger.get();
    logMessage(object, 1, "Started network server %s", address.toString(true));
}

void Server::start(unsigned short requestedPort, unsigned int flags)
{
    SocketDescriptor descriptor(requestedPort, "");
    if (!peer->start(64, flags, &descriptor, 1)) {
        String message("Failed to start network server");
        Failure failure(message);
        throwFailure(&failure, &failureType);
    }

    Address address = peer->getAddress(defaultAddress);
    port = address.port;
    report(getLogger(), address);
    update();
}
