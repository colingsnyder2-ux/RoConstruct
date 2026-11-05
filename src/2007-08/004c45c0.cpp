// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
typedef unsigned int SOCKET;
#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR (-1)
#define AF_INET 2
#define SOCK_DGRAM 2
#define SOL_SOCKET 0xffff
#define SO_REUSEADDR 0x0004
#define SO_BROADCAST 0x0020
#define SO_SNDBUF 0x1001
#define SO_RCVBUF 0x1002
#define FIONBIO 0x8004667e
#define INADDR_ANY 0
struct in_addr { unsigned long s_addr; };
struct sockaddr { unsigned short sa_family; char sa_data[14]; };
struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};
extern "C" {
__declspec(dllimport) SOCKET __stdcall socket(int af, int type, int protocol);
__declspec(dllimport) int __stdcall setsockopt(SOCKET s, int level, int optname, const char* optval, int optlen);
__declspec(dllimport) int __stdcall ioctlsocket(SOCKET s, long cmd, unsigned long* argp);
__declspec(dllimport) unsigned short __stdcall htons(unsigned short hostshort);
__declspec(dllimport) unsigned long __stdcall inet_addr(const char* cp);
__declspec(dllimport) int __stdcall bind(SOCKET s, const struct sockaddr* name, int namelen);
}
class SocketLayer {
public:
    SOCKET CreateBoundSocket(unsigned short port, bool blockingSocket, const char* forceHostAddress);
};
SOCKET SocketLayer::CreateBoundSocket(unsigned short port, bool blockingSocket, const char* forceHostAddress)
{
    SOCKET listenSocket;
    sockaddr_in listenerSocketAddress;
    int ret;

    listenSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (listenSocket == INVALID_SOCKET)
        return INVALID_SOCKET;

    int sock_opt = 1;
    setsockopt(listenSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&sock_opt, sizeof(sock_opt));
    sock_opt = 1024 * 256;
    setsockopt(listenSocket, SOL_SOCKET, SO_RCVBUF, (char*)&sock_opt, sizeof(sock_opt));
    sock_opt = 1024 * 16;
    setsockopt(listenSocket, SOL_SOCKET, SO_SNDBUF, (char*)&sock_opt, sizeof(sock_opt));

    unsigned long nonblocking = 1;
    if (ioctlsocket(listenSocket, FIONBIO, &nonblocking) != 0)
        return INVALID_SOCKET;

    setsockopt(listenSocket, SOL_SOCKET, SO_BROADCAST, (char*)&sock_opt, sizeof(sock_opt));

    listenerSocketAddress.sin_port = htons(port);
    listenerSocketAddress.sin_family = AF_INET;
    if (forceHostAddress && forceHostAddress[0])
        listenerSocketAddress.sin_addr.s_addr = inet_addr(forceHostAddress);
    else
        listenerSocketAddress.sin_addr.s_addr = INADDR_ANY;

    ret = bind(listenSocket, (struct sockaddr*)&listenerSocketAddress, sizeof(listenerSocketAddress));
    if (ret == SOCKET_ERROR)
        return INVALID_SOCKET;
    return listenSocket;
}
