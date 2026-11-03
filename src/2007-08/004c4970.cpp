// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct hostent {
    char* h_name;
    char** h_aliases;
    short h_addrtype;
    short h_length;
    char** h_addr_list;
};
struct in_addr { unsigned long s_addr; };
#define SOCKET_ERROR (-1)
extern "C" {
__declspec(dllimport) int __stdcall gethostname(char* name, int namelen);
__declspec(dllimport) struct hostent* __stdcall gethostbyname(const char* name);
__declspec(dllimport) char* __stdcall inet_ntoa(struct in_addr in);
}
#include <string.h>
class SocketLayer {
public:
    void GetMyIP(char ipList[10][16]);
};
void SocketLayer::GetMyIP(char ipList[10][16])
{
    char ac[80];
    if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR)
        return;
    struct hostent* phe = gethostbyname(ac);
    if (phe == 0)
        return;
    for (int i = 0; phe->h_addr_list[i] != 0 && i < 10; ++i)
    {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
        strcpy(ipList[i], inet_ntoa(addr));
    }
}
