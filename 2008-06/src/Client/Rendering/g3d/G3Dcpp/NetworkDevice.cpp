/**
 @file NetworkDevice.cpp

 @maintainer Morgan McGuire, morgan@cs.brown.edu
 @created 2002-11-22
 @edited  2006-02-24
 */

#include <stdlib.h>
#include <time.h>
#include "G3D/platform.h"
#include "G3D/TextOutput.h"
#include "G3D/NetworkDevice.h"
#include "G3D/NetAddress.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Log.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/stringutils.h"
#include "G3D/debug.h"

#if defined(G3D_LINUX) || defined(G3D_OSX)
    #include <unistd.h>
    #include <errno.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <netinet/tcp.h>
    #define _alloca alloca

    /** Define an error code for non-windows platforms. */
    int WSAGetLastError() {
        return -1;
    }

    #define SOCKET_ERROR -1

    static std::string socketErrorCode(int code) {
        return G3D::format("CODE %d: %s\n", code, strerror(code));
    }

    static std::string socketErrorCode() {
        return socketErrorCode(errno);
    }

    static const int WSAEWOULDBLOCK = -100;

    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;

#else 

    // Windows
    static std::string socketErrorCode(int code) {
        LPTSTR formatMsg = NULL;

        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                      FORMAT_MESSAGE_IGNORE_INSERTS |
                      FORMAT_MESSAGE_FROM_SYSTEM,
                        NULL,
                        code,
                        0,
                        (LPTSTR)&formatMsg,
                        0,
                        NULL);

        return G3D::format("CODE %d: %s\n", code, formatMsg);
    }

    static std::string socketErrorCode() {
        return socketErrorCode(GetLastError());
    }

#endif


#ifndef _SOCKLEN_T
#   if defined(G3D_WIN32) || defined(G3D_OSX)
        typedef int socklen_t;
#   endif
#endif

namespace G3D {

std::ostream& operator<<(std::ostream& os, const NetAddress& a) {
    return os << a.toString();
}


static void logSocketInfo(Log* debugLog, const SOCKET& sock) {
    uint32 val;
    socklen_t sz = 4;
    int ret;

    ret = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char*)&val, (socklen_t*)&sz);
    debugLog->printf("SOL_SOCKET/SO_RCVBUF = %d\n", val);

    ret = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char*)&val, (socklen_t*)&sz);
    debugLog->printf("SOL_SOCKET/SO_SNDBUF = %d\n", val);

    // Note: timeout = 0 means no timeout
    ret = getsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&val, (socklen_t*)&sz);
    debugLog->printf("SOL_SOCKET/SO_RCVTIMEO = %d\n", val);

    ret = getsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char*)&val, (socklen_t*)&sz);
    debugLog->printf("SOL_SOCKET/SO_SNDTIMEO = %d\n", val);
}


/////////////////////////////////////////////////////////////////////////////

/** Invokes select on one socket.  Returns SOCKET_ERROR on error, 0 if
    there is no read pending, sock if there a read pending. */
static int selectOneReadSocket(const SOCKET& sock) {
    // 0 time timeout is specified to poll and return immediately
    struct timeval timeout;
    timeout.tv_sec  = 0;
    timeout.tv_usec = 0;

    // Create a set that contains just this one socket
    fd_set socketSet;
    FD_ZERO(&socketSet); 
    FD_SET(sock, &socketSet);

    int ret = select(sock + 1, &socketSet, NULL, NULL, &timeout);

    return ret;
}


/** Returns true if the socket has a read pending */
static bool readWaiting(Log* debugLog, const SOCKET& sock) {
    int ret = selectOneReadSocket(sock);

    switch (ret) {
    case SOCKET_ERROR:
        if (debugLog) {
            debugLog->println("ERROR: selectOneReadSocket returned "
                              "SOCKET_ERROR in readWaiting().");
            debugLog->println(socketErrorCode());
        }
        // Return true so that we'll force an error on read and close
        // the socket.
        return true;

    case 0:
        return false;

    default:
        return true;
    }
}


/** Invokes select on one socket.   */
static int selectOneWriteSocket(const SOCKET& sock) {
    // 0 time timeout is specified to poll and return immediately
    struct timeval timeout;
    timeout.tv_sec  = 0;
    timeout.tv_usec = 0;

    // Create a set that contains just this one socket
    fd_set socketSet;
    FD_ZERO(&socketSet); 
    FD_SET(sock, &socketSet);

    return select(sock + 1, NULL, &socketSet, NULL, &timeout);
}

///////////////////////////////////////////////////////////////////////////////

NetworkDevice::NetworkDevice() {
    initialized     = false;
    debugLog        = NULL;
}


std::string NetworkDevice::localHostName() const {   
    char ac[128];
    if (gethostname(ac, sizeof(ac)) == -1) {
        if (debugLog) {
            debugLog->printf("Error while getting local host name\n");
        }
        return "localhost";
    }
    return gethostbyname(ac)->h_name;
}

bool NetworkDevice::init(G3D::Log* _log) {
    debugAssert(!initialized);
    debugLog = _log;

    #ifdef G3D_WIN32
        if (debugLog) {
            debugLog->section("Network Startup");
            debugLog->println("Starting WinSock networking.\n");
        }
        WSADATA wsda;		    
        WSAStartup(MAKEWORD(G3D_WINSOCK_MAJOR_VERSION, G3D_WINSOCK_MINOR_VERSION), &wsda);

        if (debugLog) {
            std::string machine = localHostName();
            std::string addr    = NetAddress(machine, 0).ipString();
            debugLog->printf(
                "Network:\n"
                "  localhost = %s (%s)\n"
                "  %s\n"
                "  Status: %s\n"
                "  Loaded winsock specification version %d (%d is "
                "the highest available)\n"
                "  %d sockets available\n"
                "  Largest UDP datagram packet size is %d bytes\n\n",
                machine.c_str(), addr.c_str(),
                wsda.szDescription,
                wsda.szSystemStatus,
                wsda.wVersion,
                wsda.wHighVersion,
                wsda.iMaxSockets,
                wsda.iMaxUdpDg);
        }
    #endif


    if (debugLog) {debugLog->section("Testing Network");}

    SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (debugLog) {debugLog->print("Open Socket                  ");}
    if (sock == SOCKET_ERROR) {
        if (debugLog) {
            debugLog->println("FAIL");
            debugLog->println(socketErrorCode());
        }
        return false;
    }
    if (debugLog) { debugLog->println("Ok"); }

    int TR = true;
    int ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, 
                         (const char*)&TR, sizeof(TR));

    if (debugLog) {debugLog->print("Enable UDP Broadcast         ");}
    if (ret != 0) {
        if (debugLog) {
            debugLog->println("FAIL");
            debugLog->println(socketErrorCode());
        }
        return false;
    }
    if (debugLog) {debugLog->println("Ok");}

    if (debugLog) {debugLog->print("Testing UDP Broadcast        ");}
    SOCKADDR_IN addr;
    int32 x;
    addr = NetAddress(0xFFFFFFFF, 23).addr;
    ret = sendto(sock, (const char*)&x, sizeof(x), 0, 
                 (struct sockaddr *) &addr, sizeof(addr));
    if (ret == SOCKET_ERROR) {
        if (debugLog) {
            debugLog->println("FAIL");
            debugLog->println(socketErrorCode());
        }
        return false;
    }
    if (debugLog) {debugLog->println("Ok");}

    if (debugLog) {debugLog->section("");}
    initialized = true;

    return true;
}


void NetworkDevice::cleanup() {
    debugAssert(initialized);

    #ifdef G3D_WIN32
        if (debugLog) {debugLog->section("Network Cleanup");}
        WSACleanup();
        if (debugLog) {debugLog->println("Network cleaned up.");}
    #endif
}


LightweightConduitRef NetworkDevice::createLightweightConduit(
    uint16                      receivePort,
    bool                        enableReceive,
    bool                        enableBroadcast) {
    
    return new LightweightConduit(this, receivePort, 
                                  enableReceive, enableBroadcast);
}


ReliableConduitRef NetworkDevice::createReliableConduit(
    const NetAddress&           address) {

    return new ReliableConduit(this, address);
}


NetListenerRef NetworkDevice::createListener(const uint16 port) {
    return new NetListener(this, port);
}
 

bool NetworkDevice::bind(SOCKET sock, const NetAddress& addr) const {
    if (debugLog) {
        debugLog->printf("Binding socket %d on port %d  ", 
                         sock, htons(addr.addr.sin_port));
    }

    if (::bind(sock, (struct sockaddr*)&(addr.addr), sizeof(addr.addr)) == 
        SOCKET_ERROR) {

        if (debugLog) {
            debugLog->println("FAIL");
            debugLog->println(socketErrorCode());
        }
        closesocket(sock);
        return false;
    }

    if (debugLog) {debugLog->println("Ok");}
    return true;
}


void NetworkDevice::closesocket(SOCKET& sock) const {
    if (sock != 0) {
        #ifdef G3D_WIN32
                ::closesocket(sock);
        #else
	        close(sock);
        #endif

        if (debugLog) {debugLog->printf("Closed socket %d\n", sock);}
        sock = 0;
    }
}


void NetworkDevice::localHostAddresses(Array<NetAddress>& array) const {
    array.resize(0);

    char ac[128];

    if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) {
        if (debugLog) {
            debugLog->printf("Error while getting local host name\n");
        }
        return;
    }

    struct hostent* phe = gethostbyname(ac);
    if (phe == 0) {
        if (debugLog) {
            debugLog->printf("Error while getting local host address\n");
        }
        return;
    }

    for (int i = 0; (phe->h_addr_list[i] != 0); ++i) {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
        array.append(NetAddress(addr));
    }    
}

///////////////////////////////////////////////////////////////////////////////

Conduit::Conduit(NetworkDevice* _nd) : binaryOutput("<memory>", G3D_LITTLE_ENDIAN) {
    sock                = 0;
    nd                  = _nd;
    mSent               = 0;
    mReceived           = 0;
    bSent               = 0;
    bReceived           = 0;
}


Conduit::~Conduit() {
    nd->closesocket(sock);
}


uint64 Conduit::bytesSent() const {
    return bSent;
}


uint64 Conduit::bytesReceived() const {
    return bReceived;
}


uint64 Conduit::messagesSent() const {
    return mSent;
}


uint64 Conduit::messagesReceived() const {
    return mReceived;
}


bool Conduit::ok() const {
    return (sock != 0) && (sock != SOCKET_ERROR);
}


bool Conduit::messageWaiting() const {
    return readWaiting(nd->debugLog, sock);
}


/**
 Increases the send and receive sizes of a socket to 2 MB from 8k
 */
static void increaseBufferSize(SOCKET sock, Log* debugLog) {

    // Increase the buffer size; the default (8192) is too easy to
    // overflow when the network latency is high.
    {
        uint32 val = 1024 * 1024 * 2;
        if (setsockopt(sock, SOL_SOCKET, SO_RCVBUF, 
                       (char*)&val, sizeof(val)) == SOCKET_ERROR) {
            if (debugLog) {
                debugLog->printf("WARNING: Increasing socket "
                                     "receive buffer to %d failed.\n", val);
                debugLog->println(socketErrorCode());
            }
        }

        if (setsockopt(sock, SOL_SOCKET, SO_SNDBUF, 
                       (char*)&val, sizeof(val)) == SOCKET_ERROR) {
            if (debugLog) {
                debugLog->printf("WARNING: Increasing socket "
                                     "send buffer to %d failed.\n", val);
                debugLog->println(socketErrorCode());
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

ReliableConduit::ReliableConduit(
    NetworkDevice*      _nd,
    const NetAddress&   _addr) : 
    Conduit(_nd), state(NO_MESSAGE), receiveBuffer(NULL),
    receiveBufferTotalSize(0), receiveBufferUsedSize(0) {

    messageType         = 0;

    addr = _addr;
    if (nd->debugLog) {nd->debugLog->print("Creating a TCP socket       ");}
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    
    if (sock == SOCKET_ERROR) {
        if (nd->debugLog) {
            nd->debugLog->println("FAIL");
            nd->debugLog->println(socketErrorCode());
        }
        nd->closesocket(sock);
        return;
    }

    if (nd->debugLog) { nd->debugLog->println("Ok"); }

    // Setup socket options (both constructors should set the same options)

    // Disable Nagle's algorithm (we send lots of small packets)
    const int T = true;
    if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, 
                   (const char*)&T, sizeof(T)) == SOCKET_ERROR) {
        
        if (nd->debugLog) {
            nd->debugLog->println("WARNING: Disabling Nagel's "
                                  "algorithm failed.");
            nd->debugLog->println(socketErrorCode());
        }
    }
    else if (nd->debugLog) {
        nd->debugLog->println("Disabled Nagel's algorithm.");
    }

    // Set the NO LINGER option so the socket doesn't hang around if
    // there is unsent data in the queue when it closes.
    struct linger ling;
    ling.l_onoff  = 0;
    ling.l_linger = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_LINGER, 
                   (const char*)&ling, sizeof(ling)) == SOCKET_ERROR) {
        
        if (nd->debugLog) {
            nd->debugLog->println("WARNING: Setting socket no linger failed.");
            nd->debugLog->println(socketErrorCode());
        }
    }
    else if (nd->debugLog) {
        nd->debugLog->println("Set socket option no_linger.");
    }

    // Set reuse address so that a new server can start up soon after
    // an old one has closed.
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, 
                   (const char*)&T, sizeof(T)) == SOCKET_ERROR) {
        
        if (nd->debugLog) {
            nd->debugLog->println("WARNING: Setting socket reuseaddr failed.");
            nd->debugLog->println(socketErrorCode());
        }
    }
    else if (nd->debugLog) {
        nd->debugLog->println("Set socket option reuseaddr.");
    }

    // Ideally, we'd like to specify IPTOS_LOWDELAY as well.

    if (nd->debugLog) {
        logSocketInfo(nd->debugLog, sock);
    }

    increaseBufferSize(sock, nd->debugLog);

    if (nd->debugLog) {nd->debugLog->printf("Created TCP socket %d\n", sock);}

    std::string x = addr.toString();
    if (nd->debugLog) {
        nd->debugLog->printf("Connecting to %s on TCP socket %d   ", 
                             x.c_str(), sock);
    }

    int ret = connect(sock, (struct sockaddr *) &(addr.addr), 
                      sizeof(addr.addr));

    if (ret == WSAEWOULDBLOCK) {
        RealTime t = System::getTick() + 5;
        // Non-blocking; we must wait until select returns non-zero
        while ((selectOneWriteSocket(sock) == 0) && (System::getTick() < t)) {
            System::sleep(0.02);
        }

        // TODO: check for failure on the select call

    } else if (ret != 0) {
        if (nd->debugLog) {
            sock = (SOCKET)SOCKET_ERROR;
            nd->debugLog->println("FAIL");
            nd->debugLog->println(socketErrorCode());
        }
        return;
    }

    if (nd->debugLog) {nd->debugLog->println("Ok");}
}


ReliableConduit::ReliableConduit(
    NetworkDevice*    _nd, 
    const SOCKET&      _sock, 
    const NetAddress&  _addr) : Conduit(_nd), state(NO_MESSAGE), 
    receiveBuffer(NULL), receiveBufferTotalSize(0), 
    receiveBufferUsedSize(0) {
    sock                = _sock;
    addr                = _addr;

    messageType         = 0;

    // Setup socket options (both constructors should set the same options)

    // Disable Nagle's algorithm (we send lots of small packets)
    const int T = true;
    if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, 
                   (const char*)&T, sizeof(T)) == SOCKET_ERROR) {
        
        if (nd->debugLog) {
            nd->debugLog->println("WARNING: Disabling Nagel's "
                                  "algorithm failed.");
            nd->debugLog->println(socketErrorCode());
        }
    }
    else if (nd->debugLog) {
        nd->debugLog->println("Disabled Nagel's algorithm.");
    }

    // Set the NO LINGER option so the socket doesn't hang around if
    // there is unsent data in the queue when it closes.
    struct linger ling;
    ling.l_onoff  = 0;
    ling.l_linger = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_LINGER, 
                   (const char*)&ling, sizeof(ling)) == SOCKET_ERROR) {
        
        if (nd->debugLog) {
            nd->debugLog->println("WARNING: Setting socket no linger failed.");
            nd->debugLog->println(socketErrorCode());
        }
    }
    else if (nd->debugLog) {
        nd->debugLog->println("Set socket option no_linger.");
    }

    // Set reuse address so that a new server can start up soon after
    // an old one has closed.
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, 
                   (const char*)&T, sizeof(T)) == SOCKET_ERROR) {
        
        if (nd->debugLog) {
            nd->debugLog->println("WARNING: Setting socket reuseaddr failed.");
            nd->debugLog->println(socketErrorCode());
        }
    }
    else if (nd->debugLog) {
        nd->debugLog->println("Set socket option reuseaddr.");
    }

    // Ideally, we'd like to specify IPTOS_LOWDELAY as well.

    if (nd->debugLog) {
        logSocketInfo(nd->debugLog, sock);
    }
}


ReliableConduit::~ReliableConduit() {
    free(receiveBuffer);
    receiveBuffer = NULL;
    receiveBufferTotalSize = 0;
    receiveBufferUsedSize = 0;
}


bool ReliableConduit::messageWaiting() const {
    ReliableConduit* me = const_cast<ReliableConduit*>(this);


    switch (state) {
    case HOLDING:
        // We've already read the message and are waiting
        // for a receive call.
        return true;

    case RECEIVING:

        if (! ok()) {
            return false;
        }
        // We're currently receiving the message.  Read a little more.
        me->receiveIntoBuffer();
     
        if (messageSize == receiveBufferUsedSize) {
            // We've read the whole mesage.  Switch to holding state 
            // and return true.
            me->state = HOLDING;
            return true;
        } else {
            // There are more bytes left to read.  We'll read them on
            // the next call.  Because the *entire* message is not ready,
            // return false.
            return false;
        }
        break;

    case NO_MESSAGE:
        if (Conduit::messageWaiting()) {
            // Message incoming.  Read the header.

            me->state = RECEIVING;
            me->receiveHeader();
            
            // Loop back around now that we're in the receive state; we
            // may be able to read the whole message before returning 
            // to the caller.
            return messageWaiting();
        } else {
            // No message incoming.
            return false;
        }
    }

    debugAssertM(false, "Should not reach this point");
    return false;
}


uint32 ReliableConduit::waitingMessageType() {
    // The messageWaiting call is what actually receives the message.
    if (messageWaiting()) {
        return messageType;
    } else {
        return 0;
    }
}


void ReliableConduit::sendBuffer(const BinaryOutput& b) {
    int ret = ::send(sock, (const char*)b.getCArray(), b.getLength(), 0);
    
    if (ret == SOCKET_ERROR) {
        if (nd->debugLog) {
            nd->debugLog->println("Error occured while sending message.");
            nd->debugLog->println(socketErrorCode());
        }
        nd->closesocket(sock);
        return;
    }

    ++mSent;
    bSent += b.getLength();

    // Verify the packet was actually sent
    // Conversion to unsigned is safe because -1 is caught earlier
    debugAssert(ret == b.getLength());
}


void ReliableConduit::send(const NetMessage* m) {
    if (m == NULL) {
        send((uint32)-1);
    } else {
        send(m->type(), *m);
    }
}


/** Null serializer.  Used by reliable conduit::send(type) */
class Dummy {
public:
    void serialize(BinaryOutput& b) const { (void)b; }
};


void ReliableConduit::send(uint32 type) {
    static Dummy dummy;
    send(type, dummy);
}


void ReliableConduit::multisend(const Array<ReliableConduitRef>& array, 
                                const NetMessage* m) {
    debugAssert(m != NULL);
    multisend(array, m->type(), *m);
}


NetAddress ReliableConduit::address() const {
    return addr;
}


bool ReliableConduit::receive(NetMessage* m) {
    if (m == NULL) {
        receive();
        return true;
    } else {
        return receive(*m);
    }
}


void ReliableConduit::receiveHeader() {
    debugAssert(state == RECEIVING);

    // Read the type
    uint32 tmp;
    int ret = recv(sock, (char*)&tmp, sizeof(tmp), 0);

    // The type is the first four bytes.  It is little endian.
    if (System::machineEndian() == G3D_LITTLE_ENDIAN) {
        messageType = tmp;
    } else {
        // Swap the byte order
        for (int i = 0; i < 4; ++i) {
            ((char*)&messageType)[i] = ((char*)&tmp)[3 - i];
        }
    }

    if ((ret == SOCKET_ERROR) || (ret != sizeof(messageType))) {
        if (nd->debugLog) {
            nd->debugLog->printf("Call to recv failed.  ret = %d,"
                                 " sizeof(messageType) = %lu\n", 
                                 ret, sizeof(messageType));
            nd->debugLog->println(socketErrorCode());
        }
        nd->closesocket(sock);
        messageType = 0;
        return;
    }

    // Read the size
    ret = recv(sock, (char*)&messageSize, sizeof(messageSize), 0);

    if ((ret == SOCKET_ERROR) || (ret != sizeof(messageSize))) {
        if (nd->debugLog) {
            nd->debugLog->printf("Call to recv failed.  ret = %d,"
                                 " sizeof(len) = %lu\n", ret, sizeof(messageSize));
            nd->debugLog->println(socketErrorCode());
        }
        nd->closesocket(sock);
        messageType = 0;
        return;
    }

    messageSize = ntohl(messageSize);
    debugAssert(messageSize < 6e6);

    debugAssert(receiveBufferUsedSize == 0);

    // Extend the size of the buffer.
    if (messageSize > receiveBufferTotalSize) {
        receiveBuffer = realloc(receiveBuffer, messageSize);
        receiveBufferTotalSize = messageSize;
    }

    if (receiveBuffer == NULL) {
        if (nd->debugLog) {
            nd->debugLog->println("Could not allocate a memory buffer "
                                  "during receivePacket.");
        }
        nd->closesocket(sock);
    }

    bReceived += 4;
}


void ReliableConduit::receiveIntoBuffer() {

    debugAssert(state == RECEIVING);
    debugAssert(messageType != 0);
    debugAssertM(receiveBufferUsedSize < messageSize, "Message already received.");
    debugAssertM(messageSize >= receiveBufferUsedSize, "Message size overflow.");

    // Read the data itself
    int ret = 0;
    uint32 left = messageSize - receiveBufferUsedSize;
    int count = 0;
    while ((ret != SOCKET_ERROR) && (left > 0) && (count < 10)) {

        ret = recv(sock, ((char*)receiveBuffer) + receiveBufferUsedSize, left, 0);

        if (ret > 0) {
            left -= ret;
            receiveBufferUsedSize += ret;
            bReceived += ret;

            if (left > 0) {
                // There's still more. Give the machine a chance to read
                // more data, but don't wait forever.

                ++count;
                System::sleep(0.001);
            }
        } else {
            // Something went wrong
            break;
        }
    }

    if ((ret == 0) || (ret == SOCKET_ERROR)) {

        if (nd->debugLog) {
            if (ret == SOCKET_ERROR) {
                nd->debugLog->printf("Call to recv failed.  ret = %d,"
                     " sizeof(messageSize) = %d\n", ret, messageSize);
                nd->debugLog->println(socketErrorCode());
            } else {
                nd->debugLog->printf("recv returned 0\n");
            }
        }
        nd->closesocket(sock);
        return;
    }

    ++mReceived;
}


///////////////////////////////////////////////////////////////////////////////

LightweightConduit::LightweightConduit(
    NetworkDevice* _nd, 
    uint16 port,
    bool enableReceive, 
    bool enableBroadcast) : Conduit(_nd) {

    if (nd->debugLog) {nd->debugLog->print("Creating a UDP socket        ");}
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (sock == SOCKET_ERROR) {
        sock = 0;
        if (nd->debugLog) {
            nd->debugLog->println("FAIL");
            nd->debugLog->println(socketErrorCode());
        }
        return;
    }
    if (nd->debugLog) {nd->debugLog->println("Ok");}

    if (enableReceive) {
        debugAssert(port != 0);
        nd->bind(sock, NetAddress(0, port));
    }

    // Figuring out the MTU seems very complicated, so we just set it to 1000,
    // which is likely to be safe.  See IP_MTU for more information.
    MTU = 1000;

    increaseBufferSize(sock, nd->debugLog);

    if (enableBroadcast) {
        int TR = true;
        if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, 
                       (const char*)&TR, sizeof(TR)) != 0) {
            if (nd->debugLog) {
                nd->debugLog->println("Call to setsockopt failed");
                nd->debugLog->println(socketErrorCode());
            }
            nd->closesocket(sock);
            return;
        }
    }

    if (nd->debugLog) {
        nd->debugLog->printf("Done creating UDP socket %d\n", sock);
    }

    alreadyReadMessage = false;
}


LightweightConduit::~LightweightConduit() {
}


void LightweightConduit::serializeMessage(const NetMessage* m, 
                                          BinaryOutput& b) const {

    if (m != NULL) {
        debugAssert(m->type() != 0);
        b.writeUInt32(m->type());
        m->serialize(b);
        b.writeUInt32(1);
    }
    
    debugAssertM(b.size() < MTU, 
                format("This LightweightConduit is limited to messages of "
                       "%d bytes (Ethernet hardware limit; this is the "
                       "'UDP MTU')", maxMessageSize()));

    if (b.size() >= MTU) {
        throw LightweightConduit::PacketSizeException(
                format("This LightweightConduit is limited to messages of "
                       "%d bytes (Ethernet hardware limit; this is the "
                       "'UDP MTU')", maxMessageSize()),
                       b.size() - 4, // Don't count the type header
                       maxMessageSize());
    }
}


void LightweightConduit::sendBuffer(const NetAddress& a, BinaryOutput& b) {
    if (sendto(sock, (const char*)b.getCArray(), b.getLength(), 0,
       (struct sockaddr *) &(a.addr), sizeof(a.addr)) == SOCKET_ERROR) {
        if (nd->debugLog) {
            nd->debugLog->printf("Error occured while sending packet "
                                 "to %s\n", inet_ntoa(a.addr.sin_addr));
            nd->debugLog->println(socketErrorCode());
        }
        nd->closesocket(sock);
    } else {
        ++mSent;
        bSent += b.getLength();
    }
}


void LightweightConduit::send(const Array<NetAddress>& array, 
                              const NetMessage* m) {
    binaryOutput.reset();
    serializeMessage(m, binaryOutput);

    for (int i = 0; i < array.size(); ++i) {
        sendBuffer(array[i], binaryOutput);
    }
}


void LightweightConduit::send(const NetAddress& a, const NetMessage* m) {
    binaryOutput.reset();
    serializeMessage(m, binaryOutput);
    sendBuffer(a, binaryOutput);
}


bool LightweightConduit::messageWaiting() const {
    // We may have already pulled the message off the network stream
    return alreadyReadMessage || Conduit::messageWaiting();
}


uint32 LightweightConduit::waitingMessageType() {
    if (! messageWaiting()) {
        return 0;
    } 

    if (! alreadyReadMessage) {
        messageBuffer.resize(8192);

        SOCKADDR_IN remote_addr;
        int iRemoteAddrLen = sizeof(sockaddr);

        int ret = recvfrom(sock, (char*)messageBuffer.getCArray(), 
            messageBuffer.size(), 0, (struct sockaddr *) &remote_addr, 
            (socklen_t*)&iRemoteAddrLen);

        if (ret == SOCKET_ERROR) {
            if (nd->debugLog) {
                nd->debugLog->println("Error: recvfrom failed in "
                        "LightweightConduit::waitingMessageType().");
                nd->debugLog->println(socketErrorCode());
            }
            nd->closesocket(sock);
            messageBuffer.resize(0);
            messageSender = NetAddress();
            messageType = 0;
            return 0;
        }

        messageSender = NetAddress(remote_addr);

        ++mReceived;
        bReceived += ret;

        messageBuffer.resize(ret, DONT_SHRINK_UNDERLYING_ARRAY);

        // The type is the first four bytes.  It is little endian.
        if (System::machineEndian() == G3D_LITTLE_ENDIAN) {
            messageType = *((uint32*)messageBuffer.getCArray());
        } else {
            // Swap the byte order
            for (int i = 0; i < 4; ++i) {
                ((char*)&messageType)[i] = messageBuffer[3 - i];
            }
        }

        alreadyReadMessage = true;
    }

    return messageType;
}


bool LightweightConduit::receive(NetAddress& sender, NetMessage* m) {

    // This both checks to ensure that a message was waiting and
    // actively consumes the message from the network stream if
    // it has not been read yet.
    uint32 t = waitingMessageType();
    if (t == 0) {
        return false;
    }

    if (m != NULL) {
        debugAssert(m->type() == t);
    }

    sender = messageSender;
    alreadyReadMessage = false;

    if (messageBuffer.size() < 4) {
        // Something went wrong
        return false;
    }

    if (m != NULL) {
        BinaryInput b((messageBuffer.getCArray() + 4), 
                      messageBuffer.size() - 4, 
                      G3D_LITTLE_ENDIAN, BinaryInput::NO_COPY);
        m->deserialize(b);
    }

    return true;
}


///////////////////////////////////////////////////////////////////////////////

NetListener::NetListener(NetworkDevice* _nd, uint16 port) {
    nd = _nd;

    // Start the listener socket
    if (nd->debugLog) {nd->debugLog->print("Creating a listener            ");}
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    
    if (sock == SOCKET_ERROR) {
        if (nd->debugLog) {
            nd->debugLog->printf("FAIL");
            nd->debugLog->println(socketErrorCode());
        }
        return;
    }
    if (nd->debugLog) {nd->debugLog->println("Ok");}
    
    if (! nd->bind(sock, NetAddress(0, port))) {
        if (nd->debugLog) {nd->debugLog->printf("Unable to bind!\n");}
        nd->closesocket(sock);
        sock = (SOCKET)SOCKET_ERROR;
        return;
    }

    if (nd->debugLog) {
        nd->debugLog->printf("Listening on port %5d        ", port);
    }

    // listen is supposed to return 0 when there is no error.
    // The 2nd argument is the number of connections to allow pending
    // at any time.
    int L = listen(sock, 100);
    if (L == SOCKET_ERROR) {
        if (nd->debugLog) {
            nd->debugLog->println("FAIL");
            nd->debugLog->println(socketErrorCode());
        }
        nd->closesocket(sock);
        sock = (SOCKET)SOCKET_ERROR;
        return;
    }
    if (nd->debugLog) {
        nd->debugLog->println("Ok");
        nd->debugLog->printf("Now listening on socket %d.\n\n", sock);
    }
}


NetListener::~NetListener() {
    nd->closesocket(sock);
}


ReliableConduitRef NetListener::waitForConnection() {

    // The address of the connecting host
    SOCKADDR_IN    remote_addr;
    int iAddrLen = sizeof(remote_addr);

    if (nd->debugLog) {
        nd->debugLog->println("Blocking in NetListener::waitForConnection().");
    }

    SOCKET sClient = accept(sock, (struct sockaddr*) &remote_addr, 
                            (socklen_t*)&iAddrLen);

    if (sClient == SOCKET_ERROR) {
        if (nd->debugLog) {
            nd->debugLog->println("Error in NetListener::acceptConnection.");
            nd->debugLog->println(socketErrorCode());
        }
        nd->closesocket(sock);
        return NULL;
    }

    if (nd->debugLog) {
        nd->debugLog->printf("%s connected, transferred to socket %d.\n", 
                             inet_ntoa(remote_addr.sin_addr), sClient);
    }

    #ifndef G3D_WIN32
        return new ReliableConduit(nd, sClient, 
                     NetAddress(htonl(remote_addr.sin_addr.s_addr), 
                                ntohs(remote_addr.sin_port)));
    #else
        return new ReliableConduit(nd, sClient, 
                    NetAddress(ntohl(remote_addr.sin_addr.S_un.S_addr), 
                               ntohs(remote_addr.sin_port)));
    #endif
}


bool NetListener::ok() const {
    return (sock != 0) && (sock != SOCKET_ERROR);
}


bool NetListener::clientWaiting() const {
    return readWaiting(nd->debugLog, sock);
}

////////////////////////////////////////////////////////////////////////////////////////////////

void NetworkDevice::describeSystem(
    TextOutput& t) {

    t.writeSymbols("Network", "{");
    t.writeNewline();
    t.pushIndent();

    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();
}


void NetworkDevice::describeSystem(
    std::string&        s) {

    TextOutput t;
    describeSystem(t);
    t.commitString(s);
}

} // namespace
